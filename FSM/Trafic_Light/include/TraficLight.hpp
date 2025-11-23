#ifndef TraficLight_hpp
# define TraficLight_hpp
#include <unistd.h>
#include <iostream>

enum STATE{
	RED,
	GREEN,
	YELLOW
};

class TraficLight
{
	private:
		enum STATE t_light;
		std::string to_string(enum STATE s);
	public:
		TraficLight();
		void install();
};

#endif