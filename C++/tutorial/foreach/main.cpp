#include "test.hpp"

void pointer(int *ptr)
{
	*ptr = 30; // derefrencing to the address
 
	std::cout << "the pointer has changed: " << *ptr << '\n';
}
void refrence(int &x)
{
	x = 20;
	std::cout << "x has changed: " << x << '\n';
}
int main()
{
	//int arr[] = {11, 3, 5, 6, 7, 8, 9, 10};
	//int len = sizeof(arr) / sizeof(arr[0]);

	//reverse_arr(arr, len);
	//sort_bouble(arr, len);
	//quick_sort(arr, 0, len-1);
	//for (int i = 0; i < len; i++)
	//{
	//	std::cout <<  arr[i]  << std::endl;
	//}
	int x = 10;
	std::cout << "after refrence: " << x << '\n';

	refrence(x);

	std::cout << "after refrence: " << x << '\n';
	
	pointer(&x);
	std::cout << "after pointer: " << x << '\n';

	//fill_array();
	return (0);
}