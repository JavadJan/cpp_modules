#include <iostream>

class Shapes
{
	public:
		double side;
	//virtual double area(){return side;} // we don't have an impelementation
	virtual ~Shapes();
};

class Squre : public Shapes
{
	public: 
		double side;
		Squre(double side): side(side){};
		//~Squre();
		virtual double area()
		{
			return (side * side);
		}
};

class Triangle : public Shapes
{
	public: 
		double side;
		Triangle(double side): side(side){};
		//~Triangle();
		double area(){
			return (0.5 * side * side);
		} 
};
int main()
{
	Shapes *shape [] =
	{
		new Triangle(5),
		new Squre (4)
	};

	for (size_t i = 0; i < 2; i++)
	{
		double are = shape[i]->area();
		std::cout << are << std::endl;
	}
	
	//Shapes shape; you can not instanciated an object from abstract class
	// but you can define a pointer from abstract class
}