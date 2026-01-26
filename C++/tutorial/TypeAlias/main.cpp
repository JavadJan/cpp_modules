#include <iostream>

void greet(int x){
	std::cout << x << std::endl;
}

int main(){
	std::pair<std::string, std::string> names;
	names = {"javad", "khavari"};
	std::cout << names.first << " " << names.second << std::endl;
	using funcPtr = void(*)(int);
	funcPtr ptr = &greet;
	ptr(5);
}