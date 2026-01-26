#include "../include/Bureaucrat.hpp"

int main()
{
	std::cout << "\033[1;31m[TEST 1:] Too Low\033[0m" << std::endl;
	try
	{
		Bureaucrat b("javad",-1);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid Grade: " << e.what() << '\n';
	}
	//std::cout << b;
	
	std::cout << "\033[1;31m\n\n[TEST 2:] Too High\033[0m" << std::endl;
	try
	{
		Bureaucrat a("Alex", 151);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid Grade: " << e.what() << '\n';
	}
	//std::cout << a;
	
	//std::cout << "\033[1;31m\n\n[TEST 3:] Too Low\033[0m" << std::endl;
	std::cout << "\033[1;31m\n\n[TEST 3:] decreament Bureaucrat \033[0m" << std::endl;
	try
	{
		Bureaucrat c("Babbe",149);
		std::cout << c << std::endl;
		c.decreamentBureaucrat();
		c.decreamentBureaucrat();
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid Grade: " << e.what() << '\n';
	}
	
	std::cout << "\033[1;31m\n\n[TEST 4:] Increament Bureaucrat\033[0m" << std::endl;
	try
	{
		Bureaucrat f("foo", 2);
		f.incrementBureaucrat();
		f.incrementBureaucrat();
	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid grade: " << e.what() << '\n';
	}
}

/* don't catch exception inside the constructor because it cause to finish the constructor
	and creation object happen, how you get that the creation happen? because destructor happen





	./bureaucrat 
[TEST 1:] Too Low
Called Bureaucrat constructor with param: -1
Invalid Grade: -1 Grade is out of range (Too Low)


[TEST 2:] Too High
Called Bureaucrat constructor with param: 151
Invalid Grade: 151 Grade is out of range (Too High)


[TEST 3:] Too Low
Called Bureaucrat constructor with param: 149
Babbe, bureaucrat grade 149


[TEST 4:] Increament Bureaucrat
Babbe demoted 150
Invalid demotion: 151 Grade is out of range (Too High)


[TEST 5:] decreament Bureaucrat 
Called Bureaucrat constructor with param: 2
foo, bureaucrat grade 2
foo promoted congragulation 🥳 1
Invalid promotion: 0 Grade is out of range (Too Low)


[TEST 6:] Too Low
Called assignment Bureaucrat operator
Called Bureaucrat destructor
Called Bureaucrat destructor
Called Bureaucrat destructor
Called Bureaucrat destructor
javad@javadkhavari$ make
c++ -Wall -Wextra -Werror -Iinclude -c src/main.cpp -o obj/main.o
successfully obj/main.o created ✅
c++ -Wall -Wextra -Werror -Iinclude -c src/Bureaucrat.cpp -o obj/Bureaucrat.o
successfully obj/Bureaucrat.o created ✅
c++ -Wall -Wextra -Werror -Iinclude obj/main.o obj/Bureaucrat.o -o bureaucrat
✅ successfully created 🏗️ 🛠️!
javad@javadkhavari$ ./bureaucrat 
[TEST 1:] Too Low
Called Bureaucrat constructor with param: -1
Invalid Grade:  Grade is out of range (Too Low)


[TEST 2:] Too High
Called Bureaucrat constructor with param: 151
Invalid Grade:  Grade is out of range (Too High)


[TEST 5:] decreament Bureaucrat 
Called Bureaucrat constructor with param: 149
Babbe, bureaucrat grade 149
Babbe demoted 150
Called Bureaucrat destructor
Invalid Grade:  Grade is out of range (Too High)


[TEST 4:] Increament Bureaucrat
Called Bureaucrat constructor with param: 2
foo, bureaucrat grade 2
foo promoted congragulation 🥳 1
Called Bureaucrat destructor
Invalid grade:  Grade is out of range (Too Low)


[TEST 6:] Too Low
javad@javadkhavari$ 
*/