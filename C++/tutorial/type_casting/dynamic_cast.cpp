#include <iostream>

class Base
{
  public:
	Base()
	{
	}
	virtual ~Base()
	{
	}
	Base(const Base &other);
	Base &operator=(const Base &other);
	virtual void makeSound() const;

};

void Base::makeSound() const
{
	std::cout << "ghaw ghaw" << std::endl;
}
class Derived : public Base
{
  public:
	Derived(){};
	~Derived(){};
	void makeSound() const
	{
		std::cout << "ghaw ghaw" << std::endl;
	}
};

int	main(void)
{
	Base *b = new Derived();
	std::cout << typeid(b).__is_function_p() << std::endl;
}
/* 
	dynamic_cast<new_type> (expression)
	if new_type is reference && casting==failed
		return bad_casting
	if (new_type is pointer && casting == failed)
		return nullptr

	class Base {
		vrtual void f(){}

	};
	class Derived: public Base{
		void f(){}
	}
	
	Base *pd = new Derived;
	Base *pb = new Base;
	
	Drived *p0= dynamic_cast<Derived *> (pd); // valid
	Drived *p1= dynamic_cast<Derived *> (pb); // invalid, why? 
*/
