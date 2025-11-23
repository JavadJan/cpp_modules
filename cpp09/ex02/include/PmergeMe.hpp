#ifndef PmergeMe_hpp
# define PmergeMe_hpp

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <cstring>
#include <sys/time.h>
#include <cstdlib> 
#include <ctype.h>
#include <fstream>
#include <iomanip>

class PmergeMe{
	private:
		std::vector<int> lst; // vector of any type can be, determin at compile-time
	public:
		PmergeMe();
		~PmergeMe();
	class Error:public std::exception{
			public:
				const char* what() const throw();
		};
};

std::vector<long> extractNum(int argc , char *argv[]);
long getTimeMicroseconds();
void printTime(long end, long begin);
void display(std::vector<long> A);
void merge(std::vector<long> &A, int l, int mid, int h);
void MergeSort(std::vector<long> &A,int l,int h);

#endif
