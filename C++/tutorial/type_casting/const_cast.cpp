#include <iostream>
#include <string>

/* 1. normally const memeber function can not modify members */
class Counter{
	int count = 0;
	public:
		void increatment() const{
			const_cast<Counter *>(this)->count++; // why *this is pointer, here is used Counter *
		}
		void display() const
		{
			std::cout << count << std::endl;
		}
};

/* 2. remove const from obj, then it can become workable */
class Printer{
	public:
		void print(){std::cout << "ptint something\n";}
};

void usePrinter(const Printer &p) // p is const, normaly it can not call print.
{
	const_cast<Printer &>(p).print(); // remove the "const" from object
	//p.print();
}

void legcyAPI(char *buffer)
{
	std::cout << buffer << std::endl;
}

/*4. Removing const from a pointer to modify data */
void	update(const int *ptr)
{
	int *x = const_cast<int *>(ptr);
	*x = 42;

}
int main()
{
	/* 1. */
	Counter co;
	co.increatment();
	co.display();

	/* 2. */
	const Printer p;
	usePrinter(p);

	/* 3. c-style, conversion const char * => char * */
	const char *str = "hello";
	legcyAPI(const_cast<char *>(str)); // remove cans again from str

	/* 4. */
	const int x = 43;
	update(&x);
	std::cout << x << std::endl;
	return (0);
}