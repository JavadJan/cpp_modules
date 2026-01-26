#include <iostream>
#include <exception>

class MyException : public std::exception{
	public:
		const char* what() const noexcept override{
			return "My custom exception happend";
		}
};

int main()
{
	try
	{
		throw MyException();
	}
	catch(const MyException& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

/* 
	exception is an object in std
	so you can easily define a derived class in c++ then write yor differnt function
*/