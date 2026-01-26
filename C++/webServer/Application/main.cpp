#include "./include/webheadr.hpp"


int main()
{
	load_env(".env");

	const char* port = getenv("SERVER_PORT");
	std::cout << "Port: " << port << std::endl;

	return (0);
}