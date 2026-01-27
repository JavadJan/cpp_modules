/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 07:02:56 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/27 08:00:12 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Sapn_hpp
# define Sapn_hpp

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
//#include <array>
#include <vector>
#include <vector>
#include <algorithm>

//###############################
//								#
//		Exceptions				#
//								#
//###############################
class IsFullException : public std::exception
{
  public:
	const char *what() const throw(){
		return "Span is full";
	}
};

class IsEmpty : public std::exception
{
  public:
	const char *what() const throw(){
		return "Span is empty";
	}
};

class NoSpanFound : public std::exception
{
  public:
	const char *what() const throw(){
		return "No span found 404!";
	}
};

class CopyException : public std::exception
{
  public:
	const char *what() const throw(){
		return "Can not copy or assignment!";
	}
};
//###############################
//								#
//			Class				#
//								#
//###############################
class Span{
	private:
		std::vector<int> numbers;
		unsigned int N;
	public:
		Span(unsigned int n):N(n)
		{
			std::cout << "\033[1;33mCalled default constructor\033[0m" <<std::endl;
		}
		~Span(){
			std::cout<<"\033[1;33mCalled destructor\033[0m" <<std::endl;
		}
		Span(const Span& other) // copy constructor
		{
			std::cout << "\033[1;33mCalled COPY constructor\033[0m" <<std::endl;
			if (other.N > N)
				throw(CopyException());
			numbers.clear();
			for (std::vector<int>::const_iterator it = other.numbers.begin(); it != other.numbers.end(); ++it)
			{
				numbers.push_back(*it);
			}
		}
		Span& operator=(const Span& other)
		{
			std::cout << "\033[1;33mCalled operator assignement\033[0m" <<std::endl;
			if (N != other.N)
				throw (CopyException());
			if (this != &other)
			{
				numbers.clear();
				for (std::vector<int>::const_iterator it = other.numbers.begin(); it != other.numbers.end(); ++it)
				{
					numbers.push_back(*it);
				}
			}
			return *this;
		}

		/* -------------------------------------------------*/
		/* 				member function						*/
		/* -------------------------------------------------*/
		int shortestSpan(){
			int dist = 2147483647; // minimun int;
			if (numbers.size() <= 1)
				throw NoSpanFound();
			std::vector<int> sorted = numbers;
			std::sort(sorted.begin(), sorted.end()); // between all number sorted
			for (size_t i = 1; i < sorted.size(); i++)
			{

				if (sorted[i] - sorted[i - 1] < dist)
					dist = sorted[i] - sorted[i - 1];
			}
			return dist;
		}
		int longestSpan()
		{
			int maxNum = *std::max_element(numbers.begin(), numbers.end());
			int minNum = *std::min_element(numbers.begin(), numbers.end());
			return std::abs(maxNum - minNum);
		}
		void display()
		{
			for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
			{
				std::cout << *it << ", ";
			}
			std::cout <<  std::endl;
		}
		//###############################
		//								#
		//			template			#
		//								#
		//###############################
		void addNumber(int x)
		{
			if (numbers.size() >= N)
				throw IsFullException();
			numbers.push_back(x);
		}
		template <typename T>
		void addNumber(T begin, T end)
		//void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
		{
			unsigned int dist = std::distance(begin, end);
			std::cout << "distance: " << dist << std::endl;
			if (numbers.size() + dist > N) // size of vecotr + dist > N => full e.g, N = 10 , dist = 5 ; size == 4 => 5 + 4 space have to store
				throw IsFullException();
			numbers.insert(numbers.end(), begin, end); //(index, first, end)
		}
};


#endif
