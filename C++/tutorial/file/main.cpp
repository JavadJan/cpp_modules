#include <fstream>
#include <iostream>

/* create a file */
void create_file()
{
	std::ofstream File("create.txt");
	File << "hello world\n";
	File << "hello javad\n";
	std::cout << "file create" << std::endl;
	File.close();
}

/* read */
#include <fstream>
#include <string>
void read_file()
{
	std::ifstream File("create.txt");
	std::string line;

	while (getline(File, line))
	{
		std::cout << line << std::endl;
	}
	File.close();
}

/* exist file */
void exist()
{
	std::ifstream file("create.txt");
	if (file.is_open())
		std::cout << "file exit\n";
	
	std::ifstream f2("test.txt");
	if (!f2.is_open())
		std::cout << "file is not exist\n";
}

/* append to file */
void append_to()
{
	std::ofstream file("create.txt", std::ios::app);
	file << "\n\n Append line";
	file.close();
}


/* count line in file */
void count_line()
{
	int count  = 0;
	std::string line;
	std::ifstream file("create.txt");
	while (getline(file, line))
	{
		count++;
	}
	std::cout << "num line: " << count << std::endl;
}

/* read file line from console: std::getline(std::cin, name) */
void read_line()
{
	std::string name;
	std::cout << "Enter your full name: ";
	std::getline(std::cin, name);
	std::cout << "Hello, " << name << "!\n";

}

/* parse string with istrinstream */
/* Treats string like a stream for parsing. */
#include <sstream>

void parse()
{
	std::string data = "John 25";
	std::istringstream ss(data);
	std::string name;
	int age;
	ss >> name >> age;
	std::cout << name << " is " << age << " years old.\n";

}

/* build a string with ostringstream */
void build_string()
{
	std::ostringstream oss;
	oss << "Name: " << "Alice" << ", Age: " << 30;
	std::string result = oss.str();
	std::cout << result << "\n";

}

/* read csv format */
void read_csv_format()
{
	std::string csv = "Alice,30,Engineer";
	std::istringstream ss(csv);

	std::string name, job;
	int age;

	getline(ss, name, ',');
	//std::cout << "name: " << name;
	ss >> age;
	//getline(ss, age, ',');
	//ss.ignore(); // skip comma

	getline(ss, job);
	std::cout << name << " is a " << age << "-year-old " << job << ".\n";

}
int main()
{
	create_file();
	read_file();
	exist();
	append_to();
	count_line();
	std::cout << "\n read csv format\n";
	read_csv_format();
	return 0;
}