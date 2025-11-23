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
		
		int shortestSpan(){
			int dist = 2147483647; // minimun int;
			if (numbers.size() <= 1)
				throw NoSpanFound();
			std::vector<int> sorted = numbers;
			std::sort(sorted.begin(), sorted.end());
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
			if (numbers.size() + dist > N)
				throw IsFullException();
			numbers.insert(numbers.end(), begin, end);
		}
};


#endif
