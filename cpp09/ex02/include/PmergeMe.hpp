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
# include <deque>
# include <sstream>
# include <sys/time.h>
# include <vector>
# include <map>
# include <algorithm>

std::vector<long> extractNum(int argc, char *argv[]);

long	getTimeMicroseconds(void);
void	printTime(long end, long begin);
void	display(std::vector<long> A);
void	merge(std::vector<std::pair<long, long> >& pairs, int l, int mid, int h);
void	MergeSort(std::vector<std::pair<long, long> >& pairs, int l, int h);

std::vector<std::pair<long, long> > formPair(std::vector<long> A);
//void sortPairsByA(std::vector<std::pair<long, long> >& pairs);
std::map<std::string, std::vector<long> > buildMainPend(std::vector<long> A);

std::vector<long> fordJohnson(std::vector<long> B);
#endif
