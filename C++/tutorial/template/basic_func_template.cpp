#include <iostream>

/* 1. basic function template*/
template <typename T>
T add (T a, T b)
{
	return (a + b);
}

/* 2. basic class template */
template <typename T1, typename T2>
class Pair{
	public:
		T1 first;
		T2 second;
		Pair(T1 a, T2 b): first(a), second(b){

		}
		void print()
		{
			std::cout << "(" << first << ", " << second << ")" << std::endl;
		}
};

/* 3. iteration template */
template <typename T, typename func>
void forEach(T *array, size_t size, func f)
{
	for (size_t i = 0; i < size; i++)
	{
		f(array[i]);
	}
	
}
template<typename T> 
void iter(T x)
{
	std::cout << "value: " << x << std::endl;
}

/* 4. template and determin an specific template */
template <typename T>
void printType(T x) {
	std::cout << "Generic type: " << x << std::endl;
}

template <>
void printType<std::string>(std::string x) {
	std::cout << "String type: " << x << std::endl;
}


/* 5. enable_if in typename, to restrict the typename */
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
process(T x) {
    std::cout << "Processing integer: " << x << std::endl;
}

int main()
{
	std::cout << "\n\n-------2.test basic function template --------\n" ;
	std::cout << add<int>(2, 4) << std::endl;
	std::cout << add<double>(2.2, 4.2) << std::endl;
	std::cout << add<float>(2.03333f, 4.5555f) << std::endl;

	std::cout << "\n\n-------2.test basic class template --------\n" ;
	Pair dic(9, 10);
	dic.print();
	
	std::cout << "\n\n-------2.test iteration template --------\n" ;
	int arr[3] = {10, 9, 11};
	forEach(arr, 3, iter<int>);

	std::cout << "\n\n-------2.test Specialized template --------\n" ;
	printType(42);              // Generic
    printType(std::string("Hi")); // Specialized

	std::cout << "\n\n-------2.test restrict typename --------\n" ;
	process(10);     // OK
    //process(3.14); // Error: not an integer
}