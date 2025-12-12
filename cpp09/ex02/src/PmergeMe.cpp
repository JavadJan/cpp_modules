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




std::vector<std::pair<long , long > > formPair(std::vector<long> A)
{
	// use push_bakc(); it use uses from resize
	std::vector<std::pair<long, long> > pairs;

	// if odd last elem be alone, without pair
	size_t odd = A.size() % 2;
	size_t len = odd ? A.size() - 1 : A.size();

	for (size_t i = 0; i < len; i+=2)
	{
		pairs.push_back(std::make_pair((std::min(A[i], A[i + 1])), std::max(A[i],A[i + 1])));
	}
	if (odd == 1)
	{
		pairs.push_back(std::make_pair(A[len], LONG_MAX));
		//pairs[i].first = A[i -2];
		//pairs[i].second = LONG_MAX; // an invalid 
	}
	return pairs;
}

bool compareBySecond(const std::pair<long, long>& p1,
                     const std::pair<long, long>& p2)
{
    return p1.second < p2.second;
}

void sortPairsByA(std::vector<std::pair<long, long> >& pairs)
{
    std::sort(pairs.begin(), pairs.end(), compareBySecond);
}



std::pair<long , long > pickb1FromSmallestPair(std::vector<std::pair<long , long > > pairs)
{
	if (pairs.empty())
        throw std::runtime_error("pairs is empty");

    std::vector<std::pair<long, long> >::const_iterator it =
        std::min_element(pairs.begin(), pairs.end());

    return *it; 
}

std::map<std::string, std::vector<long> > buildMainPend(std::vector<long> A)
{
	// build 
	std::vector<long> main;
	std::vector<long> pend;
	long leftOver = LONG_MAX;

	// cut the odd number from A
	if (A.size() % 2)
	{
		leftOver = A[A.size() -1];
		A.pop_back();
	}

	// make pairs
	std::vector<std::pair<long, long> > pairs = formPair(A);
	sortPairsByA(pairs);
	std::cout << "sorted by pairs:" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "first: " << pairs[i].first << ", second: " << pairs[i].second << std::endl;
	}

	// sort pairs by an

	// add smallest pair includeing b1
	main.push_back(pairs[0].first);
	main.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); i++)
	{
		// keep the leftover to add in pend
		if (pairs[i].second == LONG_MAX)
		{
			leftOver = pairs[i].first;
			continue;
		}

		// make main
		main.push_back(pairs[i].second);		

		// make pend witout the smallest pair
		pend.push_back(pairs[i].first);
	}

	// add left over into pend
	if (leftOver != LONG_MAX)
		pend.push_back(leftOver);
	
	// created the main and pand sequence
	std::map<std::string, std::vector<long> > main_pend;
	main_pend["main"] = main;
	main_pend["pend"] = pend;
	return (main_pend);
}

//add pend to the main by Jacobsthal rule
//void Jacobsthal(std::map<std::string, std::vector<long> > &pairs)
//{

//}



// useles
void insertionSort(std::vector<long> &main, long element)
{
	main.push_back(element);
	size_t i = main.size() - 1;
	while (i > 0 && main[i - 1] > element)
	{
		/* code */
		main[i] = main[i-1]; // shift to right
		i--;
	}
	main[i] = element;	
}