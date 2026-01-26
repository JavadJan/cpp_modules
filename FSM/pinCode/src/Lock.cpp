#include "../include/Lock.hpp"

Lock::Lock() : state(CLOSE)
{
}

std::string Lock::to_string(enum STATE s)
{
	switch (s)
	{
	case OPEN:
		return ("OPEN");
	case CLOSE:
		return ("CLOSE");
	default:
		return ("PIN CODE IS INCORRECT");
	}
}

void Lock::install()
{
	int x = 0;
	while (1)
	{
		std::cout << "Door is " << to_string(state) << " Enter Passcode: **** to " << to_string(state) << " again\n" ;
		std::cin >> x;
		switch (state)
		{
		case CLOSE:
		{
			if (x == PIN)
			{
				std::cout << "Door became open 🔓\n";
				state = OPEN;
			}
			else if (x != PIN)
			{
				std::cout << "PIN is Wrong try again: \n";
				//std::cin >> x ;
			}
			break ;
		}
		case OPEN:
		{
			if (x == PIN)
			{
				std::cout << "Door became close 🔐\n";
				state = OPEN;
			}
			else if (x != PIN)
			{
				std::cout << "PIN is Wrong try again: \n";
			}
			break ;
		}
		}
	}
}
