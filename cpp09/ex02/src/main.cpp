#include "../include/PmergeMe.hpp"


int	main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	std::vector<long> A;
	try
	{
		A = extractNum(ac, av);
		std::cout << "Before: ";
		for (size_t i = 0; i < A.size(); i++)
		{
			std::cout << A[i] << " " ;
		}
		//display(A);
		long begin = getTimeMicroseconds();
		std::vector<long> soerted = fordJohnson(A);
		long end = getTimeMicroseconds();
		
		std::cout << "sorted: " << std::endl;
		for (size_t i = 0; i < soerted.size(); i++)
		{
			std::cout << soerted[i] << " " ;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		
		// original sorted:
		std::deque<long> deq(A.begin(), A.end()); // copy
		
		long beginSTD = getTimeMicroseconds();
		std::deque<long> sortedD = fordJohnson(deq);
		long endSTD = getTimeMicroseconds();
		printTime(end, begin);
		printTime(beginSTD, endSTD);


	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	//std::vector<long> B = { 10 , 11, 9, 2, 3, 1 };
	//std::vector<long> B;
	//long arr[] = {10, 9, 11, 6, 8, 5, 2, 3, 4, 1, 14};
	//std::vector<long> B(arr, arr + sizeof(arr) / sizeof(arr[0]));
	//std::cout << "raw of : " << std::endl;
	//for (size_t i = 0; i < B.size(); i++)
	//{
	//	std::cout << B[i] << ", " ;
	//}
	std::cout << std::endl;
	//merge(B, 0, B.size()/2, B.size());
	//MergeSort(B, 0, B.size());
	//display(B);
	
	
	//std::cout << "sorted by pairs:" << std::endl;
	//for (size_t i = 0; i < pairs.size(); i++)
	//{
	//	std::cout << "first: " << pairs[i].first << ", second: " << pairs[i].second << std::endl;
	//}
	
	// after pairs it is time to make main and pend
	//std::map<std::string, std::vector<long> > main_pend = buildMainPend(B);

	//std::cout << "main: " << std::endl;
	//for (size_t i = 0; i < main_pend["main"].size(); i++)
	//{
	//	std::cout << main_pend["main"][i] << std::endl;
	//}

	//std::cout << "pend: " << std::endl;
	//for (size_t i = 0; i < main_pend["pend"].size(); i++)
	//{
	//	std::cout << main_pend["pend"][i] << std::endl;
	//}
	
	return (0);
}

/* 
	1. make piars, each pairs is sorted
	2. sort pair(bi, ai) according to second element
	3. make main: []
			pend: []
	4. 
*/