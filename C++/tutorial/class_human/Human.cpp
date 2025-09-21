#include <iostream>

class Human
{
  public:
	std::string name;
	int age;

	Human(/* args */); // declaraion contructor
	~Human();
	void eat();
	void drink();
	void sleep();
};

Human::Human(/* args */) // define constructor
{
	std::cout << "\033[1;32mA new person was born!\033[0m\n";
}

Human::~Human()
{
	std::cout << "\033[1;32mthe program has done and objects have been destroyed!\033[0m\n";
}

void Human::eat()
{
	std::cout << "human eats!\n";
}

void Human::drink()
{
	std::cout << "Human drinks\n";
}

void Human::sleep()
{
	std::cout << "Human sleeps\n";
}


int	main(void)
{
	Human person;

	person.name = "javad";
	person.age	= 34;

	std::cout << person.name << " is " << person.age << " years old\n";
	person.drink();
	person.eat();
	person.sleep();
	return (0);
}