#include "../include/BitcoinExchange.hpp"
#include <ctype.h>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const char* fielname)
{
	readDB("./db/data.csv");	
	readInput(fielname);
	getRes();
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : date_price(other.date_price) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        date_price = other.date_price;
    return *this;
}
// ##################################
//									#
//				Helper func			#
//									#
// ##################################
bool isValidDate(const std::tm &tm)
{
    // Convert to normal year/month values
    int year  = tm.tm_year + 1900; // tm_year is years since 1900
    int month = tm.tm_mon;         // tm_mon is 0–11
    int day   = tm.tm_mday;

    // Year range check
    if (year < 1900 || year > 2025)
        return false;

    // Month range check
    if (month < 0 || month > 11)
        return false;

    // Days in each month (default for non-leap years)
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    // Leap year adjustment
    bool leap = ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) );
    if (leap)
        daysInMonth[1] = 29;

    // Day range check
    if (day < 1 || day > daysInMonth[month])
        return false;

    return true;
}


std::time_t stringToTimestamp(const std::string& dateStr) {
	std::tm tm;
    std::memset(&tm, 0, sizeof(tm));

    // Example format: "2024-11-07"
    sscanf(dateStr.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);

    tm.tm_year -= 1900;  // years since 1900
    tm.tm_mon -= 1;      // months since January

	
    return std::mktime(&tm);
	//std::cout << timestamp << std::endl;
}

// ##################################
//									#
//				DB					#
//									#
// ##################################

void BitcoinExchange::readDB(const char *connection)
{
	std::ifstream File(connection);
    if (!File.is_open()) {
        throw ErrorOpen();
    }

    std::string line;
    std::getline(File, line); // skip header

    while (std::getline(File, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string dateStr, rateStr;

    	DB record;

        // split into date and price
        if (!std::getline(ss, dateStr, ',')) {
            continue;
        }
        if (!std::getline(ss, rateStr)) {
            continue;
        }

        // parse date
        unsigned long ts = stringToTimestamp(dateStr);


        long double rate = std::atof(rateStr.c_str());


        // ✅ valid record
        record.date = ts;
        record.exchange_rate = rate;
        db.push_back(record);
    }
}

// ##################################
//									#
//			GET RES					#
//									#
// ##################################
void BitcoinExchange::getRes()
{
    for (std::list<Bitcoin>::iterator it = date_price.begin();
         it != date_price.end(); ++it)
    {
        if (!it->error.empty())
            continue;

        unsigned long ts = it->date;

        long double rate = 0;
        bool found = false;

        // search in DB list
        for (std::list<DB>::iterator dbIt = db.begin();
             dbIt != db.end(); ++dbIt)
        {
            if (dbIt->date == ts)            // exact match
            {
                rate = dbIt->exchange_rate;
                found = true;
                break;
            }
            if (dbIt->date < ts)             // update closest earlier date
            {
                rate = dbIt->exchange_rate;
                found = true;
            }
        }

        if (!found)
        {
            it->error = "Error: no earlier BTC price in DB";
            continue;
        }

        it->result = it->value * rate;
    }
}

//###################################
//									#
//			PRINT					#
//									#
//###################################
void BitcoinExchange::print() const
{
    for (std::list<Bitcoin>::const_iterator it = date_price.begin();
         it != date_price.end(); ++it)
    {
        if (!it->error.empty())
        {
            std::cout << it->error << std::endl;
        }
        else
        {
            std::cout << it->dateStr
                      << " => "
                      << it->value
                      << " = "
                      << it->result
                      << std::endl;
        }
    }
}



// ##################################
//									#
//			READ					#
//									#
// ##################################

void BitcoinExchange::readInput(const char *filename)
{
    std::ifstream File(filename);
	//int i = 0;
    if (!File.is_open()) {
        throw ErrorOpen();
    }

    std::string line;
	
    if (!std::getline(File, line)) // skip header
	{
		throw (EmptyFile());
	}

    while (std::getline(File, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string dateStr, priceStr;
        Bitcoin record;
        record.error = "";

        // split into date and price
        if (!std::getline(ss, dateStr, '|')) {
            record.error = "Error: missing delimiter => " + line;
            date_price.push_back(record);
            continue;
        }
        if (!std::getline(ss, priceStr)) {
            record.error = "Error: missing price => " + line;
            date_price.push_back(record);
            continue;
        }
		
        // trim spaces
       for (int i = dateStr.size() - 1; i >= 0; i--) {
			if (dateStr[i] == ' ')
				dateStr.erase(i, 1);
		}

		for (int i = priceStr.size() - 1; i >= 0; i--) {
			if (priceStr[i] == ' ')
				priceStr.erase(i, 1);
		}

		if (!dateFormat(dateStr))
		{
			record.error = "Error: bad input => " + dateStr;
			date_price.push_back(record);
			continue;
		}

		bool bad = false;
		for (size_t i = 0; i < priceStr.length(); i++)
		{
			
			if ((priceStr[i] < '0' || priceStr[i] > '9') && priceStr[i] != '.' && priceStr[i] != '-')
			{
				bad = true;
				break;
			}
		}
		if (bad == true)
		{
			record.error = "Error: bad input =>|" + priceStr + "|";
            date_price.push_back(record);
            continue;
		}
        // parse date
        std::tm tm = time_struct(dateStr);
        if (!isValidDate(tm)) {
            record.error = "Error: Invalid date => " + dateStr;
            date_price.push_back(record);
            continue;
        }

        unsigned long ts = stringToTimestamp(dateStr);

        // parse price
        if (priceStr.empty()) {
            record.error = "Error: empty price => " + line;
            date_price.push_back(record);
            continue;
        }

        long x = std::atol(priceStr.c_str());
        if (x > 2147483647) {
            record.error = "Error: too large a number.";
            date_price.push_back(record);
            continue;
        }

		long double price = std::atof(priceStr.c_str());
        if (price < 0) {
			record.error = "Error: not a positive number.";
            date_price.push_back(record);
            continue;
        }

        // ✅ valid record
        record.date = ts;
		record.dateStr = dateStr;
        record.value = price;
        date_price.push_back(record);
		//i++;
    }
	//if (i == 0)
	//	throw BadFile();
}



void BitcoinExchange::printDB() const 
{

	for (std::list<DB>::const_iterator it = db.begin(); it != db.end(); ++it)
	{
		std::cout << "date: " << it->date
				<< ", rate: " << it->exchange_rate
				<< std::endl;
	}
}

//###################################
//									#
//			Exception				#
//									#
//###################################
const char* BitcoinExchange::ErrorOpen::what() const throw() 
{
    return "could not open file\n";
}

const char* BitcoinExchange::EmptyFile::what() const throw() 
{
    return "File is empty, nothing to parse\n";
}

const char* BitcoinExchange::BadFile::what() const throw() 
{
    return "File is false, Bad File 404!\n";
}