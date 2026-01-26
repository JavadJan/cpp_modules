#include <iostream>

namespace first
{
int		x = 1;
}

// This helps avoid name conflicts when different parts of
// your program (or libraries you use) define items with the same name.
namespace second
{
int		x = 2;
}

typedef struct
{
	std::string name;
	int	age;
}		student_t;
// don't use
// using namespace std
// cout << "hello javad"; 
// instead use std::cout << "hello javad";
int	main(void)
{
	// using name space
	using namespace second;
	std::cout << "this is javad" + first::x << "\n";
	// this is a pointer artematic not a concatenation

	// bool
	bool x = false;
	if (x)
	{
		std::cout << "hello world" << std::endl;
		x = true;
	}
	else
	{
		std::cout << "here is true" << '\n';
	}

	std::string name = "javad";
	std::cout << "hi " << name << '\n';

	// struct with typedef
	student_t std;

	std.name = "javad";
	std.age = 34;
	std::cout << std.name << "\n";
	std::cout << std.age << "\n";
	return (0);
}

/* 
public: the code inside and outside the class (gueste, nighbors)
protect: the class itself and its derived classes(not stranger), but not external code
private: your safe, only the class itself, not even sister or brother

class House {
public:
    void openFrontDoor() {
        std::cout << "Welcome to the house! (public)\n";
    }

protected:
    void accessFamilyRoom() {
        std::cout << "Only family can enter this room. (protected)\n";
    }

private:
    void openSafe() {
        std::cout << "Only I can open the safe! (private)\n";
    }
};
*/