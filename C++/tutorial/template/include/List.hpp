#ifndef List_hpp
# define List_hpp

template <typename T>
class Node{
	public:
		T data;
		Node *next;
		Node *prev;
		Node(const T& value):data(value), next(nullptr), prev(nullptr){}

};



template <typename T>
class List{
	private:
		Node<T> *current;
	public:
		class iterator{
			Node<T> *curren;
			iterator(Node<T> *ptr=nullptr): curren(ptr){}
			T& iterator*(){return current->data;}
			T& operator[](){return current->data;}

		}

		
}


#endif