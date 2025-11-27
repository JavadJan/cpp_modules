#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void print(std::vector<int> v)
{
	for (auto num : v)
		std::cout << num <<", " ;
	std::cout << std::endl;
}

int main()
{
	std::vector<int> v = {10, 9, 11, 4, 2, 5, 7, 6, 8, 14, 17, 17, 22, 2};

	//std::find – locate an element in a range.
	std::vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it != v.end())
		std::cout << "found!\n";

	// std::count – count occurrences of a value.
	std::cout << "count accurance of 2 " << std::count(v.begin(), v.end(), 2) << std::endl;
	
	// std::accumulate – sum (or combine) elements.
	std::cout << "sum: " << std::accumulate(v.begin(), v.end(), 0) << std::endl;
	
	// std::sort – sort elements in ascending order.
	std::sort(v.begin(), v.end());
	for (auto num : v)
		std::cout << num <<", " ;

	std::cout << std::endl;
	// std::reverse – reverse the order of elements.
	std::reverse(v.begin(), v.end());
	for (auto num : v)
		std::cout << num <<", " ;

	// std::max_element – find the largest element.
	std::cout << "\nmax elem: " << *std::max_element(v.begin(), v.end());
	
	// std::min_element – find the smallest element.
	std::cout << "\nmin elem: " << *std::min_element(v.begin(), v.end());
	std::cout << "\n";
	
	// std::for_each – apply a function to each element.
	std::for_each(v.begin(), v.end(), [](int x){ std::cout << x << " "; });
	std::cout << "\n";
	
	// std::transform – apply a transformation to elements.
	std::transform(v.begin(), v.end(), v.begin(), [](int x){ return x*2; });
	std::cout << "\n";
	std::for_each(v.begin(), v.end(), [](int x){ std::cout << x << " "; });
	std::cout << "\n";

	// std::remove – remove elements (returns new end).
	v.erase(std::remove(v.begin(), v.end(), 4), v.end());
	print(v);

	// std::unique – remove consecutive duplicates.
	v.erase(std::unique(v.begin(), v.end()), v.end());
	print(v);

	// std::binary_search – check if element exists in sorted range.
	std::cout << "Has 10? " << std::binary_search(v.begin(), v.end(), 10) << "\n";

	// std::equal – compare two ranges for equality.
	
	// std::copy – copy elements to another container.
	
	// std::fill – fill a range with a value.
	
	// std::replace – replace all occurrences of a value.
	
	// std::partition – split range by predicate.
	
	// std::nth_element – rearrange so nth element is in correct position.
	
	// std::shuffle – randomly shuffle elements.
	
	// std::all_of / any_of / none_of – test conditions across a range.
}
