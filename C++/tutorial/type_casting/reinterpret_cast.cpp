#include <cstdint>
#include <iostream>

class A
{
	int x1;
	int x2;

  public:
	A() : x1(10), x2(20)
	{
	}
	void printA()
	{
		std::cout << "X1: " << x1 << ", X2: " << x2 << std::endl;
	}
};
class B
{
	char c;

  public:
	B() : c('A')
	{
	}
	void printB()
	{
		std::cout << "c: " << c << std::endl;
	}
};

int	main(void)
{
	int	*x;
	A	a;
	B	b;
	A	*pa;
	B	*pb;

	// convert pointer to int
	int a1 = 70;    // 00000000 00000000 00000000 01000110
	int *ptr = &a1; // little-endial => last first: 0x46 == 70 == 'f'
	// std::uintptr_t c = reinterpret_cast<std::uintptr_t>(ptr);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	//										#
	//		casting from int* to char *		#
	//										#
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	char *pc = reinterpret_cast<char *>(ptr); // char * <= int *
	std::cout << *pc << std::endl;
	//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	//#											#
	//#		casting from integral to int *		#
	//#											#
	//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	x = reinterpret_cast<int *>(a1); // a1 == 70
	// doesn’t convert the value 70 into a pointer to that variable — 
	//it literally says “pretend the number 70 is a memory address.
	std::cout << x << std::endl;
	// std::cout << *x << std::endl;
	//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	//#											#
	//#		casting from int * to int			#
	//#											#
	//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	std::cout << sizeof(int) << " " << sizeof(int *) << " " << sizeof(long) << " " << sizeof(char *) << std::endl;
	long new_int = reinterpret_cast<long>(x); // long is 8 byte and
		//* is 8 byte either
	std::cout << new_int << std::endl;
	//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	//#											#
	//# 		casting from					#
	//#			class* to another class*		 #
	//#											#
	//#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~#
	pa = reinterpret_cast<A *>(&b);
	pb = reinterpret_cast<B *>(&a);
	pa->printA();
	pb->printB();
	a.printA();
	b.printB();
}

// convert ptr* <==> ptr1*
/*
	{
		ptr0* <==> ptr1*
	}
*/
// convert integral <==> ptr1*
/*
	{
		inegral => ptr*;
		ptr *=> integral;
	}
*/
