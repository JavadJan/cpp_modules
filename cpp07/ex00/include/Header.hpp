#ifndef header_hpp
# define header_hpp

#include <iostream>
#include <string>


//namespace functions{

	template <typename T0>
	void swap(T0 &a, T0 &b)
	{
		T0 temp;
		temp = a;
		a = b;
		b = temp;
	}
	
	template <typename T1>
	T1 const& min(T1 const&  a, T1  const&  b)
	{
		if (a < b)
			return a;
		else return (b);
	}
	
	template <typename T>
	T const& max(T  const& a, T const&   b)
	{
		return (a > b ? a : b);
	}
//}

#endif


/* 

*/