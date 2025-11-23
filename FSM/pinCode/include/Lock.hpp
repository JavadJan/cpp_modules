#ifndef Lock_hpp
# define Lock_hpp
#include <unistd.h>
#include <iostream>

# define PIN 4567

enum STATE{
	OPEN,
	CLOSE
};

class Lock
{
	private:
		enum STATE state;
		std::string to_string(enum STATE s);
	public:
		Lock();
		void install();
};

#endif