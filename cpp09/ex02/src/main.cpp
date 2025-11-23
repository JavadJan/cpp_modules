#include "../include/PmergeMe.hpp"


int	main(int ac, char *av[])
{
	
	long begin = getTimeMicroseconds();
	std::vector<long> A;
	try
	{
		A = extractNum(ac, av);
		std::cout << "Before: ";
		display(A);
		long end = getTimeMicroseconds();
		printTime(end, begin);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//std::vector<long> B = { 10 , 11, 9, 2, 3, 1 };
	//std::vector<long> B;
	long arr[] = {10, 9, 11, 6, 8, 5, 2, 3, 4, 1, 14};
	std::vector<long> B(arr, arr + sizeof(arr) / sizeof(arr[0]));

	//merge(B, 0, B.size()/2, B.size());
	MergeSort(B, 0, B.size());
	display(B);
	
	
	return (0);
}
