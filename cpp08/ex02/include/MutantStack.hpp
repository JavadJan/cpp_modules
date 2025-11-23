#ifndef MutantStack_hpp
# define MutantStack_hpp

#include <iostream>
#include <vector>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{
	private:
		std::vector<T> data; // vector of any type can be, determin at compile-time
	public:
		MutantStack(){
			std::cout << "Called Constructor" << std::endl;
		};
		~MutantStack(){};
		MutantStack(const MutantStack &other)
		{
			data = other.data;
		}
		//################# subclass iterator
		class iterator{
			private:
				typename std::vector<T>::iterator it;
			public:
				//using myIterator = std::vector<T>::iterator it;
				typedef typename std::vector<T>::iterator iter; 
				//constructor
				iterator(typename std::vector<T>::iterator itr): it(itr){
					std::cout << "Called default iterator Constructor" << std::endl;
				}

				T &operator*(){
					return *it;
				}
				iterator&operator++(){ // ++x
						this->it++;
					return (*this);
				}
				iterator operator++(int){ // return a copy, not with a refrence
					iterator temp = *this;
					this->it++;
					return (temp);
				}
				iterator &operator--(){
						this->it--;
					return (*this);
				}
				iterator operator--(int){ // return a copy, not a by refrence
					iterator temp = *this;
					this->it--;
					return (temp);
				}
				bool operator!=(const iterator& other) const { return it != other.it; }
			};
			
		iterator begin(){return iterator(data.begin());}
		iterator end(){return iterator(data.end());}
		void push(const T& value){data.push_back(value);}
		void pop(){if(!data.empty()) data.pop_back();}
		T top() {
			if (data.empty()) throw std::out_of_range("Stack is empty");
			return data.back();
		}

		bool empty(){return data.empty();}
		size_t size(){
			return data.size();
		}
		void display(){
			for (int i = 0; i < data.size(); i++) {
 				std::cout << data[i] << "\n";
			}
			
		}

};

template <typename T>
std::ostream    &operator<<(std::ostream &out, MutantStack<T> const &st){
	for (typename std::vector<T>::const_iterator it = st.data.begin(); it != st.data.end(); ++it)
            out << *it << " ";
	return out;
}

#endif
