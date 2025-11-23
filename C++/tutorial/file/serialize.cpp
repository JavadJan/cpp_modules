/*
Serialization means converting an object's data into a format that can be stored (e.g.,
	in a file) and later reconstructed. In C++,
	this is often done manually using ofstream.
*/

#include <iostream>
#include <fstream>

class Person
{
	public:
	std::string name;
	int age;
	void save(const std::string& filename)
	{
		std::ofstream File(filename);
		File << name << std::endl;
		File << age << std::endl;
	}
};

class Prodcuct{
	public:
		std::string name;
		double price;
		void write(std::ofstream& out)
		{
			out << name << ", " << price << std::endl;
		}
};

#include <vector>


int main()
{
	Person p;
	p.name = "javad";
	p.age = 34;
	p.save("info.txt");


	/* store record */
	std::vector<Prodcuct> products = {
		{"Laptop", 599.99},
		{"pc", 499.99},
		{"iphone", 1299.99},
	};
	std::ofstream out("produxt.csv");
	for (auto& p0 :  products)
	{
		p0.write(out);
	}
	
}