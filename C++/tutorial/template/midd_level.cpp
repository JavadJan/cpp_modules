#include <iostream>
#include <vector>
#include <type_traits>

/* 1. generic stack; create stack with any type of data*/
template <typename T>
class Stack{
	private:
		std::vector<T> data;
	public:
		void push(const T& value){data.push_back(value);}
		void pop(){if(!data.empty()) data.pop_back();}
		T top(){if(!data.empty()) return data.back();}
		bool empty(){return data.empty();}
		void display(){
			for (int i = 0; i < data.size(); i++) {
 				std::cout << data[i] << "\n";
			}
			
		}
};

/* 2. generic linkist, create link list in any type */
template <typename T>
struct Node{
	T value;
	Node *next;
	Node(T val): value(val), next(nullptr){};
};

template <typename T>
class Linklist{
	private:
		Node<T> *head = nullptr;
	public:
		void insert(const T& val)
		{
			Node<T> *newNode = new Node<T>(val); // constructor
			newNode->next = head;
        	head = newNode;
		}
		void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << "null\n";
    	}
};


/* 3. Factorial at compile-time. not runtime recursve */
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const int value = 1;
};

/* 4. Type Traits: IsPointer */
template<typename T>
struct isPointer{
	static const bool value = false;
};

template<typename T>
struct isPointer<T *>
{
	static const bool value = true;
};

/* 5. Enable If: Restrict Function to Integers */
template <typename T>
std::enable_if_t<std::is_integral<T>::value, void>
printIfInt(T val) {
	std::cout << "Integer: " << val << std::endl;
}


int main()
{
	std::cout << "first test" << std::endl;
	Stack<int> intStack; // Stack<int>: we are passing the type of data. 
	intStack.push(10);
	intStack.push(20);
	intStack.display();
	std::cout << "\n\n ---------second test" << std::endl;
	Linklist<int> ls;
	ls.insert(10);
	ls.insert(11);
	ls.insert(9);
	ls.print();
	std::cout << "\n\n ---------Factorial test" << std::endl;
	std::cout << Factorial<5>::value << std::endl;

	std::cout << "\n\n ---------detect type of value" << std::endl;
	std::cout << isPointer<int>::value << std::endl;   // false
    std::cout << isPointer<int*>::value << std::endl;  // true
	
	std::cout << "\n\n ---------This prevents the function from compiling if T is not an integer." << std::endl;
	int a = 5;
	std::string name = "javad";
	printIfInt(5);
	printIfInt(a);
	//printIfInt(name); // Error 🚫

}