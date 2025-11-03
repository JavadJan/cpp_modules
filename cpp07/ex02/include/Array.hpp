#ifndef Array_hpp
# define Array_hpp

#include <iostream>

template <typename T>
class Array{
	private:
		T *elements;
		unsigned int _size;
	public:
		Array():elements(NULL), _size(0)
		{
			//Construction with no parameter: Creates an empty array.
			std::cout << "\033[1;33mCalled Default constructor\033[0m" << std::endl;
		}
		Array(unsigned int n):elements(new T[n]), _size(n)
		{
			// Construction with an unsigned int n as a parameter: Creates an array of n elements
			//initialized by default.
			//Tip: Try to compile int * a = new int(); then display *a.
			std::cout << "\033[1;33mCalled Parameterized constructor\033[0m" << std::endl;
		}
		Array(const Array &other):elements(new T[other._size]), _size(other._size)
		{
			for (unsigned int i = 0; i < _size; i++)
			{
				elements[i] = other.elements[i];
			}
		}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete [] elements;
				this->_size = other._size;
				this->elements = new T[other._size];
				for (unsigned int i = 0; i < _size; i++)
				{
					elements[i] = other.elements[i];
				}
			}
			return (*this);
		}
		unsigned int size() const
		{
			return (this->_size);
		}
		T& operator[](size_t index)
		{
			if (index >= size())
			{
				throw std::out_of_range("Index out of bounds"); // check bounds
			}	
			/* Elements can be accessed through the subscript operator: [ ] */
			return (elements[index]);
		}

		void display()
		{
			for (unsigned int i = 0; i < _size; i++)
			{
				std::cout << this->elements[i] << " ";
			}
			std::cout << " called size(): "<< size() << " " << std::endl;
		}
		~Array()
		{
			std::cout << "\033[1;33mCalled destructor\033[0m" << std::endl;
			delete [] this->elements;
		}
};


#endif
