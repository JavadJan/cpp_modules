#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main()
{

	Data *a = new Data;
	a->name = "javad";
	a->tel = 1313656566;

	uintptr_t rw = Serializer::serialize(a);
	std::cout << rw << std::endl; 

	Data* deserialized = Serializer::deserialize(rw);
	std::cout << deserialized->name <<std::endl;
	std::cout << deserialized->tel <<std::endl;
	delete a;
}