#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[DEBUG]: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup " 
			<< "burger. I really do!\n";
}

void Harl::info()
{
	std::cout << "[INFO]: I cannot believe adding extra bacon costs more money. You didn’t put" 
				<< "enough bacon in my burger! If you did, I wouldn’t be asking for more! \n";
}

void Harl::warning()
{
	std::cout << "[WARNING]: I think I deserve to have some extra bacon for free. I’ve been coming for"
				<< "years, whereas you started working here just last month. \n";
}

void Harl::error()
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now.\n";
}

Harl::Harl(){
	std::cout << "\033[1;32mDefault Constructor called\033[0m" << std::endl;
}
Harl::~Harl(){
	std::cout << "\033[1;31mDestructor called\033[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	//pointer to a member function of the class Harl
	//typedef void (Harl::*Func)(); // a ptr to member Harl
	/* this is typedef, it can act like other typedef e.g., int, double or string */
	//represents a pointer to a member function of Harl, e.g.,{debug, info, wearning, error}
	/* array of function pointer */
	/* void (*arr[]) = {fucn1, func2, func3, func4}; */
	/* int (*arr_artemetic[]) = {add, devide, multible, subtrac} */
	std::string levels[] = {"debug", "info", "warning", "error"};
	//Func call_func[] = {&Harl::debug, &Harl::info, &Harl::warning,&Harl::error};
	void (Harl::*arr[])() = {&Harl::debug, &Harl::info, &Harl::warning,&Harl::error};
	for (size_t i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*arr[i])();  // <-- call member function
			return ;
		}
	}
	
	//fptr = &add;	fptr = &Harl::add; this just take the address point -> address
	//call_level(level);
}

/* 
	1. int (*ptr_func)() = function;
	2. void (*ptr_func)() = &function;
	3. void (*array[])(int, int) = {&add, &sub, &multiply, &devision};

	4. Class* ptr = &obj; → pointer to the object.
	5. Type Class::*m = &Class::member; → pointer to a specific member.
*/