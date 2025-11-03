#include <iostream>
/* Variadic, arbitary number of template args 
	#it run recursive at compile-time not runtime
*/
void print() // base case
{
	std::cout << "done" << std::endl; // 
}
template <typename T, typename... Rest>
void print(T first, Rest ...rest)
{
	std::cout << first << " " << std::endl;
	print(rest...);
}
/* TRACE OF EXECUTION 
	print(1, 2.5, "hello", 'A')
	↓
	print(2.5, "hello", 'A')
	↓
	print("hello", 'A')
	↓
	print('A')
	↓
	print()

*/
/*2. variadic template recursion */
template <typename T>
T sum(T value) // base case
{
	return value;
}

template <typename T, typename... Rest>
T sum(T first, Rest... rest)
{
	return (first + sum(rest...));
}
/* TRACE AT COMPILE_TIME:
	sum(1, 2, 3, 4)
	→ 1 + sum(2, 3, 4)
		→ 2 + sum(3, 4)
				→ 3 + sum(4)
					→ 4  (base case)

*/

int main()
{
	print(1, 2.2, 2.3f, "hello", 'A');
	std::cout << "\n\n-----------[TEST] variadic template" << std::endl;
	int s = sum(1,2, 3, 4);
	std::cout << s << std::endl;
}