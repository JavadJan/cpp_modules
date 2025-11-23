#ifndef header_hpp
# define header_hpp

# include <algorithm>
# include <iostream>
# include <string>
# include <array>
# include <vector>
# include <list>

class MyException : public std::exception
{
  public:
	const char *what() const throw(){
		return "Not found, 404!";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw MyException();
	return (it);
}
#endif

/*

*/