#include <iostream>
#include <string>
#include <sstream>

class A{
	int value;

	public:
		A(){std::cout << "default constructor" << std::endl;};
		A(int x):value(x){std::cout << "constructor with param" << std::endl;}
		int getVal(){return this->value;}

		operator std::string(){
			//return std::to_string(value);
			std::ostringstream oss;
        	oss << value;
        	return oss.str();
		}
};


int main()
{

	A a;
	std::cout << "\n\ntest implicit casting" << std::endl;
	a = 10; // worked: constructor conversion, implicity conversion

	std::cout << "\n\ntest construtor without conversion" << std::endl;
	A b(10);

	std::cout << "\n\ntest constructor with converion static_cast: " << std::endl;
	a = static_cast<A>(50);// it is more readble;
	std::string str = a; // work, but it's not good we are assigning the object to straing
	std::cout << "a: " << a.getVal() << " b: " << b.getVal() << std::endl;
	std::cout << str << std::endl;
}