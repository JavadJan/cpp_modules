#include "Copy.hpp"
#include <fstream>

static size_t ft_strlen(char *str)
{
	size_t i;

	for (i = 0; str[i]; i++){}
	return (i);	
}

int main(int ac, char **av)
{
	size_t len = ft_strlen(av[2]);

	if (ac < 4)
	{
		std::cout << "Invalid parametes\n";
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
	std::string outputFileName = std::string(av[1]) + ".replace";
	std::ofstream ofile(outputFileName, std::ios::app);
	while (getline(file, line))
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