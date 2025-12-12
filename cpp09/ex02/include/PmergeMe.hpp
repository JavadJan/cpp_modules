#ifndef PmergeMe_hpp
# define PmergeMe_hpp

# include <climits>
# include <cstdlib>
# include <cstring>
# include <ctype.h>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <list>
# include <sstream>
# include <sys/time.h>
# include <vector>
# include <map>
#include <algorithm>

class PmergeMe
{
  private:
	std::vector<int> lst; // vector of any type can be, determin at compile-time
  public:
	PmergeMe();
	~PmergeMe();
	class Error : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::vector<long> extractNum(int argc, char *argv[]);
long	getTimeMicroseconds(void);
void	printTime(long end, long begin);
void	display(std::vector<long> A);
void	merge(std::vector<long> &A, int l, int mid, int h);
void	MergeSort(std::vector<long> &A, int l, int h);

// 1. make pait a list of number, leave odd alone
std::vector<std::pair<long, long> > formPair(std::vector<long> A);
void sortPairsByA(std::vector<std::pair<long, long> >& pairs);
std::map<std::string, std::vector<long> > buildMainPend(std::vector<long> A);

// make pair recursivley.
// make pairs of number and sort by the biggest until not possibel to make form
// and sort them by the biggest
// [10, 2, 11, 5, 4] => (10, 2), (11, 5), (4) => [11]=> 
#endif
