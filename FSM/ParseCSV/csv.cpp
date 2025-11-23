#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>

//enum STATE {
//	START,
//	END,
//	CONETENT,
//	PIPE,
//	COMMA,
//	ERR
//}
struct record {
    unsigned long timestamp = 0;
    double price = 0.0;
    std::string invalid_row;
};

enum STATE {
    START_ROW,
    PARSE_DATE,
    PARSE_PRICE,
    VALIDATE_ROW,
    ERROR_ROW
};
#include <cstring>

std::tm toTime(std::string date)
{
	std::tm tm;
	memset(&tm, 0, sizeof(tm));

	sscanf(date.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);

    tm.tm_year -= 1900;  // years since 1900
    tm.tm_mon -= 1;      // months since January

    return tm;
}
int main(int ac, char *av[])
{
	if (ac != 2)
	{
		printf("invalid arg: \n");
		return 1;
	}
	/* define the data structure that you want to turn it */
	std::vector<record> csv;

	/* open file to read from it */
	std::ifstream File(av[1]);
	if (!File.is_open())
	{
		std::cout << "Error: failed to open file \n";
		return 1;
	}
	
	// absoreb first line
	std::string line;
	std::getline(File, line);
	std::cout << line << std::endl;
	
	// convert string to a sstream, to aus stream function
	//std::stringstream s(line);
	
	// second line
	std::getline(File, line);
	std::cout << line << std::endl;

	int i = 0;
	while (std::getline(File, line) && i < 10)
	{
		// convert string to stream
		std::stringstream s(line);
	
		// split string to the
		std::string date;
		std::string rate;
		std::getline(s, date, ',');
		std::getline(s, rate);
	
		double rt = std::stof(rate);
		std::tm tm = toTime(date);
		printf("%ld\n", std::mktime(&tm));
		std::cout << "year: " << tm.tm_year<< ", month: " << tm.tm_mon << ", day: " << tm.tm_mday << std::endl;
		std::cout << "[" << i++ << "]" << "date: " << date << ", rate: " << rt << std::endl;

	}
	
	return (0);
}