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
void	printTime(long end, long begin, size_t _size);
void	display(std::vector<long> A);
void	merge(std::vector<std::pair<long, long> >& pairs, int l, int mid, int h);
void	MergeSort(std::vector<std::pair<long, long> >& pairs, int l, int h);

std::vector<std::pair<long, long> > formPair(const std::vector<long>& A);
std::vector<std::pair<long, long> > formPairDEQUE(const std::deque<long>& A);

std::map<std::string, std::vector<long> > buildMainPend(std::vector<long> A);

std::map<std::string, std::deque<long> > buildMainPendDEQUE(std::deque<long> A);

std::vector<long> fordJohnson(std::vector<long> B);


std::deque<long> fordJohnsonDEQUE(std::deque<long> B);


#endif
