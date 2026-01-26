#include <iostream>
#include <exception>
void grandchild() {
    throw std::runtime_error("Error in grandchild");
}

void child() {
    try {
        grandchild();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught in child\n";
        throw; // rethrow to parent
    }
}

void parent() {
    try {
        child();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught in parent\n";
    }
}



int main()
{
	//std::string word = "four";
	////std::cout << word.at(4) << std::endl; // get the letter at index 3
	//try
	//{
	//	//if (word.at(4))
	//	std::cout << word.at(4) << std::endl; // get the letter at index 3
	//	//else
	//	//	throw "not found";
	//	int *arr = new int[999999999999999999];
	//		throw std::exception(); // throw 

	//}
	//catch(std::exception& e)
	//{
	//	//catch(std::out_of_range& e)
	//	std::cout << "What is thrown: " << e.what() << '\n';
	//}
	//catch (std::bad_alloc &bad)
	//{
	//	std::cout << "Mem: " << bad.what() << std::endl;
	//}
	parent();
}

// exception is base standard class that have lost of derived class e.g., bad_alloc, logic_error, out_of_range