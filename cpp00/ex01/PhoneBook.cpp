#include "./include/PhoneBook.hpp"

PhoneBook::PhoneBook(Contact contact[])
{
	for (int i = 0; i < 8; ++i) {
		this->contact[i] = contact[i];
	}
	std::cout << "\033[1;32mA contact added into Phonebook!\033[0m\n";
}
PhoneBook::PhoneBook()
{
    this->count = 0;
    std::cout << "\033[1;32m[INFO] PhoneBook created!\033[0m\n";
}

PhoneBook::~PhoneBook()
{
	//std::cout << "\031[1;32mPhonebook has been destroiyed!\031[0m\n";
}

int unkown_cmd(std::string state)
{
	if (state != "SEARCH" || state != "search" || state != "EXIT" ||
		state != "exit" || state != "ADD" || state != "exit")
		return (1);
	return (0);
}

int PhoneBook::exit()
{
	std::cout << "exited!\n";
	return (0);
}
int	main(void)
{
	std::string temp;
	std::string name;
	std::string l_name;
	std::string nickname;
	std::string tel;

	int count = 0;
	std::string state;

	PhoneBook phonebook;
	std::cout << "Hi, Welcome you can add 8 contact\n"
				<< std::endl;
	while (1)
	{
		std::cout << "'EXIT' to exit, 'SEARCH' to search in Phonebook, 'ADD' to add new contact: ";
		
		std::getline(std::cin, state);

		if (std::cin.eof())
		{
			std::cout << "\nCtrl+D detected. Exiting cleanly.\n";
			exit(0);
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "ERROR Input failed.\n";
			continue;
		}
		if (state.empty()) // press Enter
			continue;
		if (state == "EXIT" || state == "exit")
		{
			return (phonebook.exit());
		}
		else if (state == "ADD" || state == "add")
		{
			std::cout << "run add method\n";
			name = get_value("Enter your Firsname:");
			
			l_name = get_value("Enter your Lastname: "); 
			
			nickname = get_value("Enter your Nickname: "); 
			
			tel = get_value("Enter your Phone Number: "); 

			Contact contact(name, l_name, nickname, tel, "hah", ++count);

			phonebook.add(contact, count);
			continue ;
		}
		else if (state == "SEARCH" || state == "search")
		{
			phonebook.search();
		}
		else if (unkown_cmd(state))
		{
			std::cout << "Unkown command choose from list command\n";
			continue;
		}		
	}
	return (0);
}
