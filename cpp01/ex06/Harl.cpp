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
Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level)
{
	std::string levels [] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int expr = -1;

	typedef void (Harl::*func_ptr)();
	func_ptr call_func [] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			expr = i;
			break;
		}
	}
	if (expr == -1)
	{
		std::cout << "level is not found, or miss seppelling!\n";
		return ;
	}
	for (size_t j = expr; j < 4; j++)
	{
		switch (j)
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
	

}