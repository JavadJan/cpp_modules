#include <iostream>
#include <signal.h>
#include <string.h>
#include <unistd.h>

enum	STATE
{
	START,
	ACCEPT,
	ERROR
};

bool	fsm_accept(std::string &input)
{
	enum STATE	state;
	char		symbole;

	state = START;
	for (size_t i = 0; i < input.size(); i++)
	{
		symbole = input[i];
		switch (state)
		{
		case START:
		{
			if (symbole == '1')
				state = ACCEPT;
			else
				state = ERROR;
			break ;
		}
		case ACCEPT:
			break;
		case ERROR:
			break;
		default:
			break ;
		}
	}
	return state == ACCEPT;
}

//	L = {w | w start with 1}
//	alphabet = {0, 1}
int	main(void)
{
	std::string l0 = "011";
	std::string l1 = "100";

	std::cout << ((fsm_accept(l0) == ACCEPT) ? "accpted" : "ERROR") << std::endl;
	std::cout << ((fsm_accept(l1) == ACCEPT) ? "accpted" : "ERROR") << std::endl;
}