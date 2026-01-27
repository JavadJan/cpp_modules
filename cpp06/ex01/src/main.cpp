/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:17:30 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:17:32 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};

int main()
{

	Data *a = new Data;
	a->name = "javad";
	a->tel = 1313656566;

	std::cout << "original: " << std::endl;
	std::cout << "name: " << a->name <<  std::endl;
	std::cout << "original: " << a->tel << std::endl << std::endl;


	uintptr_t rw = Serializer::serialize(a);
	std::cout << "serialized: " << rw << std::endl << std::endl; 

	Data* deserialized = Serializer::deserialize(rw);
	std::cout << "name after desrialized: " << deserialized->name <<std::endl;
	std::cout << "tel after desrialized: " << deserialized->tel <<std::endl << std::endl;
	delete a;

	

    return 0;
}
/* 
	reinterpret_cast is a very special and dangerous type of casting operator. And is suggested to use it using proper data type i.e., (pointer data type should be same as original data type).
	It can typecast any pointer to any other data type.
	It is used when we want to work with bits.
	If we use this type of cast then it becomes a non-portable product. So, it is suggested not to use this concept unless required.
	It is only used to typecast any pointer to its original type.
	Boolean value will be converted into integer value i.e., 0 for false and 1 for true.

	------------------------------------------
	// int *p = new int(100);
	// std::cout << *p << std::endl;
	// std::cout << p << std::endl;

	// char *c = reinterpret_cast<char *>(p);
	// std::cout << *c << std::endl;
	// std::cout << c << std::endl;

	mystruct s;

    // Assigning values
    s.x = 5;
    s.y = 11;
    s.c = 'a';
    s.b = true;

    // data type must be same during casting
    // as that of original

    // converting the pointer of 's' to,
    // pointer of int type in 'p'.
    int* p = reinterpret_cast<int*>(&s);

    std::cout << sizeof(s) << std::endl;

    // printing the value currently pointed by *p
   std::cout << *p << std::endl;

    // incrementing the pointer by 1
    p++;

    // printing the next integer value
    std::cout << *p << std::endl;

    // p++;

    // we are casting back char * pointed
    // by p using char *ch.
    // char* ch = reinterpret_cast<char*>(p);

    // printing the character value
    // pointed by (*ch)
    // cout << *ch << endl;

    // ch++;

	since, (*ch) now points to boolean value,
    so it is required to access the value using 
    same type conversion.so, we have used 
    data type of *n to be bool.

    // bool* n = reinterpret_cast<bool*>(ch);
    // cout << *n << endl;

    // we can also use this line of code to
    // print the value pointed by (*ch).
    // cout << *(reinterpret_cast<bool*>(ch));
*/