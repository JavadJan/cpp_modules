/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:47:21 by mkhavari          #+#    #+#             */
/*   Updated: 2026/01/28 14:47:28 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void printTime(long end, long begin, size_t _size)
{
	float duration = (static_cast<double>(end) - begin) / 1000000;
	//std::cout << "duration: " << (end - begin) << "=> "<< static_cast<double>(end - begin) / 100 << std::endl;

    std::cout << "Time to process a range of " 
              << _size
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


void merge(std::vector<std::pair<long, long> >& pairs, int l, int mid, int h)
{
    int i = l;
    int j = mid + 1;

    std::vector<std::pair<long, long> > B;
	//pre-allocates memory so the vector can grow efficiently without repeated reallocations in push_back().
    B.reserve(h - l);

    while (i <= mid && j < h)
    {
        if (pairs[i].second < pairs[j].second)
            B.push_back(pairs[i++]);
        else
            B.push_back(pairs[j++]);
    }

    while (i <= mid)
        B.push_back(pairs[i++]);

    while (j < h)
        B.push_back(pairs[j++]);

    for (int k = 0; k < (int)B.size(); ++k)
	{
		//std::cout << "low: " << l << std::endl;
        pairs[l + k] = B[k];
	}
}

void MergeSort(std::vector<std::pair<long, long> >& pairs, int l, int h)
{
    if (h - l <= 1)
		return;  // 0 or 1 element → sorted

    int mid = (l + h - 1) / 2;

    MergeSort(pairs, l, mid + 1);   // left part
    MergeSort(pairs, mid + 1, h);   // right part
    merge(pairs, l, mid, h);
}



/*[STEP 1]:  Make pairs (a0, b0), (a1, b1), (a2, b2), ...  */
std::vector<std::pair<long , long > > formPair(const std::vector<long>& A)
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

std::vector<std::pair<long , long > > formPairDEQUE(const std::deque<long>& A)
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

	// [STEP 1] make pairs
	std::vector<std::pair<long, long> > pairs = formPair(A);

	// [STEP 2] sort pairs by second (a0, b0), (a1, b1), (a2, b2), ...
	//sortPairsByA(pairs);
	MergeSort(pairs, 0, pairs.size());
	//std::cout << "sorted by pairs:" << std::endl;
	//for (size_t i = 0; i < pairs.size(); i++)
	//{
	//	std::cout << "first: " << pairs[i].first << ", second: " << pairs[i].second << std::endl;
	//}

	// add smallest pair includeing b1
	// [STEP 3] create MAIN list and PEND list
	main.push_back(pairs[0].first);
	main.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); i++)
	{
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


std::map<std::string, std::deque<long> > buildMainPendDEQUE(std::deque<long> A)
{
	// build 
	std::deque<long> main;
	std::deque<long> pend;

	long leftOver = LONG_MAX;

	// cut the odd number from A
	if (A.size() % 2)
	{
		leftOver = A[A.size() -1];
		A.pop_back();
	}

	// [STEP 1] make pairs
	std::vector<std::pair<long, long> > pairs = formPairDEQUE(A);

	// [STEP 2] sort pairs by second (a0, b0), (a1, b1), (a2, b2), ...
	//sortPairsByA(pairs);
	MergeSort(pairs, 0, pairs.size());
	//std::cout << "sorted by pairs:" << std::endl;
	//for (size_t i = 0; i < pairs.size(); i++)
	//{
	//	std::cout << "first: " << pairs[i].first << ", second: " << pairs[i].second << std::endl;
	//}

	// add smallest pair includeing b1
	// [STEP 3] create MAIN list and PEND list
	main.push_back(pairs[0].first);
	main.push_back(pairs[0].second);

	for (size_t i = 1; i < pairs.size(); i++)
	{
		// make main
		main.push_back(pairs[i].second);		

		// make pend witout the smallest pair
		pend.push_back(pairs[i].first);
	}

	// add left over into pend
	if (leftOver != LONG_MAX)
		pend.push_back(leftOver);
	
	// created the main and pand sequence
	std::map<std::string, std::deque<long> > main_pend;
	main_pend["main"] = main;
	main_pend["pend"] = pend;
	return (main_pend);
}

//add pend to the main by Jacobsthal rule
std::vector<int> genJacobList(int n)
{
	std::vector<int> out;
	if (n < 0)
		return out; // or throw std::invalid_argument("Negative input not allowed");

	out.push_back(1); // 1
	if (n == 0)
		return out;

	out.push_back(1);
	if (n == 1)
		return out;

	int i = 2;
	while (true)
	{
		int next = out[i - 1] + 2 * out[i - 2];
		if (next - 1 < 0)
			continue;
		if (next > n )
			break ;
		out.push_back(next);
		i++;
	}
	
	return out;
}


std::vector<int> uniqueConsecutive(const std::vector<int> &v)
{
    std::vector<int> out;
	if (v.empty())
		return out;

	// Ensure v is not empty before accessing v[0]
	out.push_back(v[0]);

    for (size_t i = 1; i < v.size(); ++i)
    {
        if (v[i] != v[i-1])
            out.push_back(v[i]);
    }
    return out;
}

// search in binary with upper_bound and insert
void binaryInsert(std::vector<long> &v, long x)
{
    std::vector<long>::iterator it =
        std::upper_bound(v.begin(), v.end(), x);
    v.insert(it, x);
}

void binaryInsertDEQUE(std::deque<long> &d, long x)
{
    std::deque<long>::iterator it =
        std::upper_bound(d.begin(), d.end(), x);
    d.insert(it, x);
}


void Jacobsthal(std::map<std::string, std::vector<long> > &main_pend)
{

	std::vector<long> &main = main_pend["main"];
    std::vector<long> &pend = main_pend["pend"];

	size_t n = main_pend["pend"].size(); // number for elemnt for jacobsthal list
	if (n == 0)
		return;
	std::vector<int> listJ = genJacobList(n); // it generate the duplicate elem
	std::vector<int> uListJac   = uniqueConsecutive(listJ); // remove the duplication

	int lastJ = -1;

	for (size_t i = 0; i < uListJac.size(); ++i)
    {
        int j = uListJac[i];
        if ((size_t)j >= n)
            continue;

        // insert pend[j]
        binaryInsert(main, pend[j]);

        // insert in-gap block (descending)
        int k = j - 1;
        while (k > lastJ)
        {
            binaryInsert(main, pend[k]);
            --k;
        }

        lastJ = j;
    }

    // Insert remaining elements after final Jacobsthal
    int k = lastJ + 1;
    while ((size_t)k < n)
    {
        binaryInsert(main, pend[k]);
        ++k;
    }
	
}


void JacobsthalDEQUE(std::map<std::string, std::deque<long> > &main_pend)
{

	std::deque<long> &main = main_pend["main"];
    std::deque<long> &pend = main_pend["pend"];

	size_t n = main_pend["pend"].size(); // number for elemnt for jacobsthal list
	if (n == 0)
		return;
	std::vector<int> listJ = genJacobList(n); // it generate the duplicate elem
	std::vector<int> uListJac   = uniqueConsecutive(listJ); // remove the duplication

	int lastJ = -1;

	for (size_t i = 0; i < uListJac.size(); ++i)
    {
        int j = uListJac[i];
        if ((size_t)j >= n)
            continue;

        // insert pend[j]
        binaryInsertDEQUE(main, pend[j]);

        // insert in-gap block (descending)
        int k = j - 1;
        while (k > lastJ)
        {
            binaryInsertDEQUE(main, pend[k]);
            --k;
        }

        lastJ = j;
    }

    // Insert remaining elements after final Jacobsthal
    int k = lastJ + 1;
    while ((size_t)k < n)
    {
        binaryInsertDEQUE(main, pend[k]);
        ++k;
    }
	
}


std::vector<long> fordJohnson(std::vector<long> B)
{
	std::map<std::string, std::vector<long> > main_pend = buildMainPend(B);
	Jacobsthal(main_pend);
	return (main_pend["main"]);
}


std::deque<long> fordJohnsonDEQUE(std::deque<long> B)
{
	std::map<std::string, std::deque<long> > main_pend = buildMainPendDEQUE(B);

	JacobsthalDEQUE(main_pend);
	return (main_pend["main"]);
}