#ifndef RPN_hpp
# define RPN_hpp

#include <iostream>
#include <stack>



class RPN{
	private:
		std::stack<int> stack;
		void eval(const char *postfix);
	public:
		RPN();
		~RPN();
		RPN(const char*filname);
		//RPN(const RPN &other);
		
		class Error:public std::exception{
			public:
				const char* what() const throw();
		};
};


//std::ostream& operator<<(std::ostream& out, const RPN& st) {
//    out << "Date: " << st.getDate() << ", Price: " << st.getPrice();
//    return out;
//}


#endif
