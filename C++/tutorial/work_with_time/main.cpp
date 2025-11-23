#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

int	main(void)
{
	/* convert this string time to timestamp */
	std::string dateStr = "2025-03-29";
	std::tm tm = {};
	std::istringstream ss(dateStr);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	std::cout << ss.bad() << std::endl;

	time_t timestamp = mktime(&tm);
	std::cout << timestamp << std::endl;

	/* current time */
	std::time_t now = std::time(nullptr); // current timestamp
	std::cout << "Timestamp: " << now << "\n";

	std::tm *localTime = std::localtime(&now); // convert to local time
	std::cout << "year: " << localTime->tm_year << std::endl;
	std::cout << "month: " << localTime->tm_mon << std::endl;
	std::cout << "day: " << localTime->tm_mday << std::endl;
	std::cout << "Date: " << std::put_time(localTime, "%Y-%m-%d	%H:%M:%S") << "\n";
}