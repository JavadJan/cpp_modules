#include "../include/Span.hpp"

int main()
{
	int arr[] = {6, 3, 17, 9, 10, 11, 11};
	try
	{
		//###############################
		//								#
		//			vector				#
		//								#
		//###############################
		std::cout << "\033[1;32m[TEST:] test with vector\033[0m" << std::endl;
		Span s(7);
		//s.addNumber(4);
		std::vector<int> numbers(arr, arr+ (sizeof(arr) / sizeof(arr[0])));
		s.addNumber(numbers.begin(), numbers.end());
		s.display();
		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//###############################
	//								#
	//			list				#
	//								#
	//###############################
	try
	{
		std::cout << "\033[1;32m\n\n[TEST:] test with list\033[0m" << std::endl;
		Span s0(2); // ensure capacity for at least two numbers
		std::list<int> numbers0 (arr, arr + 3);
		s0.addNumber(numbers0.begin(), numbers0.end());
		s0.display();
		std::cout << s0.shortestSpan() << std::endl;
		std::cout << s0.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//###############################
	//								#
	//			100 numbers			#
	//								#
	//###############################
	std::cout << "\033[1;32m\n\n[TEST 100:] test with vector\033[0m" << std::endl;
	Span hunderd(100);
	srand(time(0)); // gen diff every time program run
	std::vector<int> v;
	for (size_t i = 0; i < 100; i++)
	{
		int randNum = rand() % 10000;
		v.push_back(randNum);
	}
	hunderd.addNumber(v.begin(), v.end());

	std::cout << hunderd.shortestSpan() << std::endl;
	std::cout << hunderd.longestSpan() << std::endl;
	try
	{
		//std::cout << randNum << std::endl;
		hunderd.addNumber(100000);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//###############################
	//								#
	//			10,000				#
	//								#
	//###############################
	
	std::cout << "\033[1;32m\n\n[TEST 10,000:] test with vector\033[0m" << std::endl;
	Span t(10000);
	srand(time(0)); // gen diff every time program run
	std::vector<int> v0;
	for (size_t i = 0; i < 10000; i++)
	{
		int randNum = rand() % 1000000;
		v0.push_back(randNum);
	}
	t.addNumber(v0.begin(), v0.end());

	std::cout << t.shortestSpan() << std::endl;
	std::cout << t.longestSpan() << std::endl;
	try
	{
		//std::cout << randNum << std::endl;
		t.addNumber(1000000);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

