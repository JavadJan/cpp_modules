#include "./include/PhoneBook.hpp"

void	display_phonebook(Contact contact[], int count);

void	print_cell(int y)
{
	std::cout << y;
	for (size_t i = 0; i < 9; i++)
	{
		std::cout << ' ';
	}
}
void	print_cell(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << '.';
	}
	else
	{
		std::cout << str;
		for (size_t i = 0; i < (10 - str.length()); i++)
		{
			std::cout << ' ';
		}
	}
}

void PhoneBook::add(Contact contact, int count)
{
	this->contact[(count - 1) - (8 * ((count - 1) / 8))] = contact; // this->contact[count %8]
	std::cout << "try to add new contact in phonebook\n";
	display_phonebook(this->contact, count);
}

void	display_phonebook(Contact contact[], int count)
{
	int limit = std::min(count, 8);
	std::cout << "\033[1;32m|\033[0m";
	print_cell("Index");

	std::cout << "\033[1;32m|\033[0m";
	print_cell("Firstname");


	std::cout << "\033[1;32m|\033[0m";
	print_cell("Lastname");


	std::cout << "\033[1;32m|\033[0m";
	print_cell("Nickname");

	std::cout << "\033[1;32m|\033[0m";
	print_cell("Phone Num");

	std::cout << "\033[1;32m|\033[0m";
	std::cout << '\n';

	for (size_t y = 0; y < limit; y++)
	{
		std::cout << "\033[1;32m|\033[0m";
		print_cell(contact[y].getIndex());
		//print_cell(y - 1);

		std::cout << "\033[1;32m|\033[0m";
		print_cell(contact[y].getName());

		std::cout << "\033[1;32m|\033[0m";
		print_cell(contact[y].getLastName());

		std::cout << "\033[1;32m|\033[0m";
		print_cell(contact[y].getNickname());

		std::cout << "\033[1;32m|\033[0m";
		print_cell(contact[y].getPhoneNumber());

		std::cout << "\033[1;32m|\033[0m";
		std::cout << '\n';
	}
}

void PhoneBook::search()
{
	std::string search;

	std::cout << "run search method\n";
	search = get_value("🔍 search: ");

	bool found = false;

	Contact found_c[8];
	int	j = 0;

	for (size_t i = 0; i < 8; i++)	
	{
		const Contact &c = this->contact[i];

		if (
			c.getName().find(search)     != std::string::npos ||
			c.getLastName().find(search) != std::string::npos ||
			c.getNickname().find(search) != std::string::npos ||
			c.getPhoneNumber().find(search) != std::string::npos ||
			std::to_string(c.getIndex()).find(search) != std::string::npos
		)
		{
			std::cout << "✔️ Found match in contact index " << c.getIndex() << '\n';
			found_c[j++] = c;
 			found = true;
		}
	}

	if (!found)
		std::cout << "❌ No matching contacts found for \"" << search << "\"\n";
	else
		display_phonebook(found_c, j);
	//std::cout << "search for " << search << '\n';
	// FROM Contact WHERE {contact.name.contain(search) || contact.lastname.contain(search)
	//						contact.nickname.contain(search) || contact.tel.contain(search)
	//						contact.index.contain(search)}

}