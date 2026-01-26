#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[DEBUG]\n I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup " 
			<< "burger. I really do!\n";
}

void Harl::info()
{
	std::cout << "[info]\n I cannot believe adding extra bacon costs more money. You didn’t put" 
				<< "enough bacon in my burger! If you did, I wouldn’t be asking for more! \n";
}

void Harl::warning()
{
	std::cout << "[WARNING]\n I think I deserve to have some extra bacon for free. I’ve been coming for"
				<< "years, whereas you started working here just last month. \n";
}

void Harl::error()
{
	std::cout << "[ERROR]\n This is unacceptable! I want to speak to the manager now.\n";
}
Harl::Harl(){
	std::cout << "\033[1;32mDefault Constructor called\033[0m" << std::endl;
}
Harl::~Harl(){
	std::cout << "\033[1;31mDestructor called\033[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels [] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int expr = -1;
	int i = 0;
	//typedef void (Harl::*func_ptr)();
	void (Harl::*call_func[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	while (i < 4)
	{	
		if (levels[i] == level)
		{
			expr = i;
			break;
		}
		i++;
	}
	if (expr == -1)
	{
		std::cout << "level is not found, or miss seppelling!\n";
		return ;
	}
	switch (i)
	{
		case (0):
			(this->*call_func[0])();						
			break;
		case (1):
			(this->*call_func[1])();						
			break;
		case (2):
			(this->*call_func[2])();						
			break;
		case (3):
			(this->*call_func[3])();						
			break;
	
	default:
		break;
	}	
}