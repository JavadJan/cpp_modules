#ifndef Serializer_hpp
# define Serializer_hpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <limits>
#include <cerrno>
#include <cmath>
#include <cstdint>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
#define MIN_FLOAT -3.402823466e+38F
#define MAX_FLOAT  3.402823466e+38F

#define MIN_DOUBLE -1.7976931348623158e+308
#define MAX_DOUBLE  1.7976931348623158e+308

enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = -1
};
struct Data 
{
	int val;
};

class Serializer{

	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
	public: 
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};


#endif


/* 

min() means smallest positive non-zero value (used for denormalized range checks).

lowest() means most negative representable value — which is what you want for range

*/