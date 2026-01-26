#include <iostream>
#include <map>

int main()
{
	std::map<int, std::string>  mp = {{2, "javad"}, {1, "reza"}, {3, "Hadi"}, {0,  "Mahdi"}};
	for (std::map<int, std::string >::iterator it = mp.begin();
		it != mp.end() ; it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
	
}