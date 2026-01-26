#include <fstream>
#include <iostream>


//static size_t ft_strlen(char *str)
//{
//	size_t i;

//	for (i = 0; str[i]; i++){}
//	return (i);	
//}

int main(int ac, char **av)
{
	//size_t len = ft_strlen(av[2]);
	size_t len = std::string(av[2]).length();

	if (ac != 4)
	{
		std::cout << "Invalid argument\n";
		return (1);
	}
	std::ifstream file(av[1]);
	if (!file.is_open())
	{
		std::cout << "Failed to open the file.\n";
		return (127);
	}
	std::string line;
	std::string result;
	std::string outputFileName = std::string(av[1]) + ".replace"; // std::string(av[1]) char * to string
	std::ofstream ofile(outputFileName.c_str(), std::ios::app);
	while (getline(file, line)) // read one line and keep it in line
	{
		for (size_t i = 0; i < line.length();)
        {
            if (line.substr(i, len) == av[2]) 
            {
                result += av[3]; // append to the end of result found s1
                i += len;
            }
            else
            {
                result += line[i]; // append normal
                i++;
            }
        }
        ofile << result << '\n';
        result.clear();
	}
	file.close();
	ofile.close();
	return (0);
}

/* 
	av[1] = filename_to_open
	av[2] = 1th string, to look for as length as av[2]
	av[3] = 2th string, it should be replaced with av[2] in av[1]

	if (line[i : len] == s1 )
		result = copy from s2
	else 
		result = copy from the original
*/