/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:46:28 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 16:46:30 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Array.hpp"
#include <unistd.h>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()


// enum	cases
// {
// 	just_constructor,
// 	constructor_param,
// 	copy,
// 	assignement,
// 	at_index, // new[]
// 	bounds,
// };

// int	main(void)
// {
// 	//cases	arr[] = {just_constructor, constructor_param, copy, assignement,
// 	//		at_index, bounds};
// 	cases	current_case = bounds;

// 	//for (size_t i = 0; i < 6; i++)
// 	//{
// 	//	current_case = arr[i];
// 		switch (current_case)
// 		{
// 		case just_constructor:
// 		{
// 			//std::cout << "\033[1;31m[TEST1]: empty, array, no allocation\033[0m" << std::endl;
// 			Array<int> a;
// 			break ;
// 		}
// 		case constructor_param:
// 		{
// 			std::cout << "\033[1;31m[TEST2]: single instanceiat object\033[0m" << std::endl;
// 			Array<int> b(5);
// 			b[0] = 10;
// 			b[1] = 9;
// 			b[2] = 11;
// 			b[3] = 7;
// 			b[4] = 8;
// 			b.display();
// 			break ;
// 		}
// 		case copy:
// 		{
// 			std::cout << "\033[1;31m[TEST3]: single instanceiat object\033[0m" << std::endl;
// 			Array<int> intArr(5);
// 			intArr[0] = 10;
// 			intArr[1] = 9;
// 			intArr[2] = 11;
// 			intArr[3] = 7;
// 			intArr[4] = 8;
// 			intArr.display();

// 			Array<std::string> strArr(3);
// 			strArr[0] = "javad";
// 			strArr[1] = "evaluator";
// 			strArr[2] = "both";
// 			strArr.display();

// 			std::cout << "lets test copy constructor" << std::endl;
// 			Array<int> copy_int(intArr);
// 			intArr[1] = 6;
// 			intArr[3] = 5;
// 			std::cout << "copy: ";
// 			copy_int.display();
// 			std::cout << std::endl;
			
// 			std::cout << "modify origin: ";
// 			intArr.display();
// 			std::cout << std::endl;
			
// 			std::cout << "no change the copy version: ";
// 			copy_int.display();
// 			std::cout << std::endl;
// 			//std::cout << "\nlet's test the assignment constructor" << std::endl;
// 			//strArr = intArr;ERROR not same intstaceiate
// 			break ;
// 		}
// 		case assignement:
// 		{
// 			std::cout << "\033[1;31m[TEST4]: single instanceiat object\033[0m" << std::endl;
// 			Array<int> intArr(5);
// 			intArr[0] = 10;
// 			intArr[1] = 9;
// 			intArr[2] = 11;
// 			intArr[3] = 7;
// 			intArr[4] = 8;
// 			intArr.display();

// 			Array<int> newArr = intArr;
// 			std::cout << "test and change new arr: ";
// 			newArr[4] = 10000;
// 			newArr.display();
// 			std::cout << std::endl;
// 			std::cout << "no cahnge the origin again: ";
// 			intArr.display();
// 			break ;
// 		}
// 		case at_index:
// 		{
// 			std::cout << "\033[1;31m[TEST5]: get arr[index]\033[0m" << std::endl;
// 			Array<std::string> names(5);
// 			names[0] = "javad";
// 			names[1] = "Bob";
// 			std::cout << names[0] << ", " << names[1] << std::endl;
// 			break ;
		
// 		}
// 		case bounds:
// 		{
// 			try
// 			{
// 				std::cout << "\033[1;31m[TEST5]: Out of bound\033[0m" << std::endl;
// 				Array<std::string> names(5);
// 				names[0] = "javad";
// 				names[5] = "Bob";
// 			}
// 			catch(const std::exception& e)
// 			{
// 				std::cerr << e.what() << '\n';
// 			}
			
// 			break ;
// 		}
// 		}
// 	//	sleep(5);
// 	//}
// }

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}