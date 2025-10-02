#include <iostream>

int riskyOperation()
{

}


int main()
{
	std::string word = "four";
	//std::cout << word.at(4) << std::endl; // get the letter at index 3
	try
	{
		//if (word.at(4))
		std::cout << word.at(4) << std::endl; // get the letter at index 3
		//else
		//	throw "not found";
		int *arr = new int[999999999999999999];
		throw std::exception(); // throw 

	}
	catch(std::exception& e)
	{
		//catch(std::out_of_range& e)
		std::cout << "What is thrown: " << e.what() << '\n';
	}
	//catch (std::bad_alloc &bad)
	//{
	//	std::cout << "Mem: " << bad.what() << std::endl;
	//}
	
}

// exception is base standard class that have lost of derived class e.g., bad_alloc, logic_error, out_of_range