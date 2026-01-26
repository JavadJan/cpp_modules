#include <iostream>

class Simple
{
	private:
		int size;
		int *A;
	public: 
		int x;

		Simple():size(0){}
		Simple(int n): size(n)
		{
			this->A = new int[n];

			for (int i = 0; i < size; i++)
			{
				this->A[i] = 0; // create object with N element of Zero
			}
			
		}
		void setA(int i, int val)
		{
			this->A[i] = val;
		}
		int getIndexValue(int i)
		{
			return (this->A[i]);
		}
		int getSize(){
			return (this->size);
		}
};



class Heap
{
	private:
		Simple *simple;
	public:
		Heap(int set_x)
		{
			this->simple = new Simple;
			this->simple->x = set_x;
			std::cout << "Param constructor" << std::endl;
		}

		Heap(const Heap& other)
		{
			simple = new Simple(*other.simple);	
		}

		Heap& operator=(const Heap& other) // without this both object has the same memory
		{
			*this->simple = *other.simple;// deep copy of contents
			return (*this);
		}


		~Heap()
		{
			delete simple;
		}

		int getSimple(){ // whenever you define provate member it is neccessry to implement the getter and setter
			return (this->simple->x);
		}
		void setSimpleX(int x)
		{
			this->simple->x = x;
		}
};

int main()
{
	Heap heapA(4);
	Heap heapB(5);

	heapB = heapA; // useing assignment constructor
	Heap c(heapB); // using copy constructor

	std::cout << heapA.getSimple() << std::endl;
	std::cout << heapB.getSimple() << std::endl;
	
	heapB.setSimpleX(20); // here just B has been changed but without deep copy both is changed
	std::cout << heapA.getSimple() << std::endl;
	std::cout << heapB.getSimple() << std::endl;
	std::cout << c.getSimple() << std::endl;


}