#include "../include/PmergeMe.hpp"

std::vector<long> extractNum(int argc , char *argv[])
{
	std::vector<long> numbers;
	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];

		// Remove quotes if present
		if (!arg.empty() && arg[0] == '"')
			arg.erase(0, 1);
		if (!arg.empty() && arg[arg.size() - 1] == '"')
			arg.erase(arg.size() - 1, 1);

		// Use istringstream to split by spaces
		std::istringstream iss(arg);
		std::string token;
		while (iss >> token)
		{
			/* no digit error! */
			for (size_t i = 0; i < token.size(); i++)
			{
				if (!std::isdigit(token[i]) && token[i] != '+')
					throw std::invalid_argument("Error: no digit! " + token);
			}
			
			//check negative
			long num = std::atol(token.c_str());
			if (num < 0)
				throw (std::invalid_argument("Error: Negative number!"));
			numbers.push_back(num);
		}
	}
	return numbers;
}

long getTimeMicroseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);  
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

void printTime(long end, long begin)
{
	float duration = (static_cast<double>(end) - begin) / 1000000;
	std::cout << "duration: " << (end - begin) << "=> "<< static_cast<double>(end - begin) / 100 << std::endl;

    std::cout << "Time to process a range of " 
              << 5
              << " elements with std::vector : "
			  << std::setprecision(9)
              << duration 
              << " us"
              << std::endl;
}

void display(std::vector<long> A)
{
	for (size_t i = 0; i < A.size(); ++i) {
		std::cout << A[i] << " ";
    }
	std::cout << std::endl;
}
void merge(std::vector<long> &A, int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;

    std::vector<long> B;
    B.reserve(h - l);

    while (i <= mid && j < h)
    {
        if (A[i] < A[j])
            B.push_back(A[i++]);
        else
            B.push_back(A[j++]);
    }

    while (i <= mid)
        B.push_back(A[i++]);

    while (j < h)
        B.push_back(A[j++]);

    for (int k = 0; k < (int)B.size(); ++k)
	{
		//std::cout << "low: " << l << std::endl;
        A[l + k] = B[k];
	}
}

void MergeSort(std::vector<long> &A, int l, int h)
{
    if (h - l <= 1)
		return;  // 0 or 1 element → sorted

    int mid = (l + h - 1) / 2;

    MergeSort(A, l, mid + 1);   // left part
    MergeSort(A, mid + 1, h);   // right part
    merge(A, l, mid, h);
}
