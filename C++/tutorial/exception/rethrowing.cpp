#include <iostream>
#include <stdexcept>

void riskyOperation(int x){
	try
	{
		if (x == 0)
			throw std::runtime_error("Inner: zero not allowed!");
		if (x < 0)
			throw std::invalid_argument("Inner: negative not allowed");

	}
	catch (const std::invalid_argument& e) {
        std::cout << "Handled inside function: " << e.what() << std::endl;
        throw; // rethrow to caller
    }
}

int main() {
    try {
        riskyOperation(-3);
    }
    catch (const std::runtime_error& e) {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught in main: " << e.what() << std::endl;
    }
}