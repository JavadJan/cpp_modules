#include <iostream>
#include<list>
#include <deque>
#include <queue>

template <typename T>
class Queue
{
	private:
		std::list<T> queue;

	public:
		Queue(){};
		~Queue(){

		};
		//add element at the end
		void push(const T& x){
			queue.push_back(x);
		}

		void pop(){
			if (!queue.empty()) {
            	queue.pop_front();
        	} else {
            	throw std::out_of_range("Queue is empty");
        	}
		}; //→ remove element from the front

		T& front(){
			if (!queue.empty()) {
        		return queue.front();
        	} else {
            	throw std::out_of_range("Queue is empty");
        	}
		} //→ access first element

		bool empty()
		{
			return queue.empty();
		}; // → check if queue is empty		
		size_t size() const {
        	return queue.size();
    	}
};

int main()
{
	Queue<int> q;
	q.push(10);
	q.push(9);
	q.push(11);
	q.push(14);
	q.push(7);
	q.push(6);
	q.push(8);	
}