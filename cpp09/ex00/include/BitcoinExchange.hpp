#ifndef BitcoinExchange_hpp
# define BitcoinExchange_hpp

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <cstdlib>   // for atof

enum State {
    START_FIELD,
    IN_FIELD,
    END_FIELD,
    END_ROW
};

struct Bitcoin
{
	unsigned long date;
	long double value;

	double result;
	std::string dateStr;
	std::string error;
};

struct DB
{
	unsigned long date;
	long double exchange_rate;
};

class BitcoinExchange{
	private:
	std::list<Bitcoin> date_price;
	//std::vector<DB> db;
	std::list<DB> db;
	//T date;
	//T1 price;
	void 	readInput(const char *filename);
	void	readDB(const char *connettion);
	void 	getRes();
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const char*filname);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void print() const;
		void printDB() const;
		/* customize exception: */
		class ErrorOpen:public std::exception{
			public:
				const char* what() const throw();
		};
		class EmptyFile:public std::exception{
			public:
				const char* what() const throw();
		};
		class BadFile:public std::exception{
			public:
				const char* what() const throw();
		};
};

bool	dateFormat(std::string dateStr);
std::tm time_struct(const std::string& dateStr);

//std::ostream& operator<<(std::ostream& out, const BitcoinExchange& st) {
//    out << "Date: " << st.getDate() << ", Price: " << st.getPrice();
//    return out;
//}


#endif
