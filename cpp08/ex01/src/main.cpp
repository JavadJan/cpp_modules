/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:02:50 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/27 13:12:39 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

enum STATE {
	CORECT_V,
	FULL,
	EMPTY,
	OUT_BOUND,
	HUNDERED,
	BIG,
	MAX,
	SIZE_ONE
};

int main()
{
	enum STATE s = MAX;

	int arr[] = {6, 3, 17, 9, 10, 11, 11};
	switch (s)
	{
	case CORECT_V:
	{
		try
		{
			//###############################
			//								#
			//			vector				#
			//								#
			//###############################
			std::cout << "\033[1;32m[TEST 1:] test with vector, correct face\033[0m" << std::endl;
			Span s(7); // size N == 7
			//s.addNumber(4);
			std::vector<int> numbers(arr, arr+ (sizeof(arr) / sizeof(arr[0]))); // convert to the vector

			s.addNumber(numbers.begin(), numbers.end()); // add a vector.
			s.display();

			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		break;
	}
	case FULL:
	{
		try
		{
			//###############################
			//								#
			//			vector	FULL		#
			//								#
			//###############################
			std::cout << "\033[1;32m[TEST 1:] test when vector is full\033[0m" << std::endl;
			Span s(7); // size N == 7
			//s.addNumber(4);
			std::vector<int> numbers(arr, arr+ (sizeof(arr) / sizeof(arr[0]))); // convert to the vector

			s.addNumber(numbers.begin(), numbers.end()); // add a vector.
			s.display();

			s.addNumber(10);
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
	}
	case EMPTY:
	{
		try
		{
			//###############################
			//								#
			//			vector	empty		#
			//								#
			//###############################
			std::cout << "\033[1;32m[TEST 1:] test when vector is full\033[0m" << std::endl;
			Span s(7); // size N == 7
			std::cout << s.shortestSpan() << std::endl;
			std::cout << s.longestSpan() << std::endl;
		}
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
	}
	case BIG:
	{
		//###############################
		//								#
		//			10,000				#
		//								#
		//###############################
		
		std::cout << "\033[1;32m\n\n[TEST 10,000:] test with vector\033[0m" << std::endl;
		srand(time(0)); // gen diff every time program run
		std::vector<int> v0;
		Span t(10000);
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
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
	}
	case HUNDERED:
	{
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
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
	}
	case OUT_BOUND:
	{
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
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
	}
	case SIZE_ONE:
	{
		//###############################
		//								#
		//  find path with size one		#
		//								#
		//###############################
		try
		{
			std::cout << "\033[1;32m\n\n[TEST:] test with size one\033[0m" << std::endl;
			Span s0(1); // ensure capacity for at least two numbers

			s0.addNumber(10);
			s0.display();
			
			std::cout << s0.shortestSpan() << std::endl;
			std::cout << s0.longestSpan() << std::endl;
		}
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
	}
	case MAX:
	{
		//###############################
		//								#
		//			10,000				#
		//								#
		//###############################
		
		try
		{
			std::cout << "\033[1;32m\n\n[TEST 10,000:] test with 10,000,000\033[0m" << std::endl;
			Span t(10000000);
			srand(time(0)); // gen diff every time program run
			std::vector<int> v0;
			for (size_t i = 0; i < 10000000; i++)
			{
				int randNum = rand() % 2147483647;
				v0.push_back(randNum);
			}
			t.addNumber(v0.begin(), v0.end());

			std::cout << t.shortestSpan() << std::endl;
			std::cout << t.longestSpan() << std::endl;

		}
		catch(NoSpanFound& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsFullException& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(IsEmpty& e)
		{
			std::cerr << e.what() << '\n';
		}
		break;
	}
	default:
		break;
	}
}

