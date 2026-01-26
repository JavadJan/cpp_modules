#include "./include/PhoneBook.hpp"

std::string get_value(std::string msg)
{
	std::string value;

	while (1)
	{
		std::cout << msg;
		if (!std::getline(std::cin, value))
		{
			// If EOF (Ctrl+D) or stream error
			if (std::cin.eof())
			{
				std::cout << "\nEnd of input (Ctrl+D). Exiting cleanly.\n";
				exit(0);  // Clean exit
			}
			else
			{
				std::cin.clear();              // clears the error state of the std::cin stream.
				std::cin.ignore(1000, '\n');   //  ignores up to 1000 characters or until a newline
				std::cout << "ERROR Input failed. Please try again.\n";
				continue;
			}
			
		}

		if (value.empty())
		{
			std::cout << "Input cannot be empty. Try again.\n";
			continue;
		}
		break;
	}
	return (value);
}