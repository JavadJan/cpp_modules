#include <iostream>

class Student 
{
	public: 
		std::string name;
		Student(std::string name): name(name){};
		virtual ~Student(){
			std::cout << "base destrutor called" << std::endl;
		}
		virtual void print(){
			std::cout << name << std::endl;
		}
};

class MedicalStuden:public Student
{
	public:
		std::string speciality;
		MedicalStuden(std::string name, std::string spe): Student(name), speciality(spe){};
		~MedicalStuden(){std::cout << "\033[33mMedicallStuden Destrucot calles\033[0m" << std::endl;}
		void print() {
			std::cout << name << " " << speciality << std::endl;
		}
};

void increamnet(int &x)
{
	x++;
	std::cout << "after increament: " << x << std::endl;
}
int main()
{
	Student *studens[] = 
	{
		new Student("javad"),
		new Student("Reza"),
		new Student("Najla"),
		new MedicalStuden("Mohmoodi", "Mahdi"),
		new MedicalStuden("Mahmoodi","Ehsan"),
		new MedicalStuden("mahmoodi","Narges")
	};
	for (size_t i = 0; i < 6; i++)
	{
		studens[i]->print();
	}
	for (size_t i = 0; i < 6; i++)
	{
		delete studens[i];
	}
	
	int a = 4;
	std:: cout << "\n\nbefore increament: " << a << std::endl;
	increamnet(a);
	std:: cout << "after increament(): " << a << std::endl;

}
