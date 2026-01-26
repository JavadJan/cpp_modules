#include <iostream>
// Include the vector library
#include <vector>

// Include the list library
#include <list>

// Include the set library
#include <set>

// Include the map library
#include <map>

// Include the stack library
#include <stack>

// Include the queue library
#include <queue>
#include <sstream>
#include <string>
int main()
{
	 /* 1. Vector */
	std::vector<int> numbrs = {10, 9, 11, 6, 8, 5, 2, 3, 4, 1, 14};
	for (int n: numbrs)
		std::cout << n << " " ;
	std::cout << numbrs.front()<< std::endl;;
	std::cout << numbrs.back()<< std::endl;;
	numbrs.push_back(7);
	std::cout << numbrs.back() << std::endl;
	std::cout << numbrs.at(1) << std::endl;
	//numbrs.clear();
	std::cout << std::endl;

	/* 2. list */
	std::list<int> lst;
	for (size_t i = 0; i < 10; i++)
	{
		lst.push_back(i);
	}
	
	char str[] = "hello my name is javad";
	std::string s = str;

	std::istringstream iss(s);

	std::string ss;
	while (iss >> ss)
	{
		std::cout << ss << std::endl;
	}
	
	//int a, b , c;
	//iss >> a >> b >> c;
	//std::cout << a << b << c ;
	
}