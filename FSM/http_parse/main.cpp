#include <iostream>
#include <unistd.h>

enum	STATE
{
	REQ_LINE,
	HEADER,
	BODY,
	DONE,
	ERROR
};

int	main(int argc, char const *argv[])
{
	enum STATE	state;

	if (argc != 2)
	{
		std::cout << "bad config\n";
		return (1);
	}
	std::cout << "config file: " << argv[1] << std::endl;
	std::string buffer;
	state = REQ_LINE;
	while (std::getline(std::cin, buffer))
	{
		switch (state)
		{
		case REQ_LINE:
		{
			// fill method, version, path
			std::cout << "parsing the req_line\n";
			break ;
		}
		case HEADER:
		{
			// if exist key value it is header
			break ;
		}
		case BODY:
		{
			break;
		}
		case DONE:
		{
			break;
		}
		case ERROR:
		{
			break;
		}
		default:
			break ;
		}
	}
	
	return (0);
}
