/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:25:21 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 16:37:21 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_hpp
# define iter_hpp

#include <iostream>

/* 
	The first parameter is the address of an array.
	The second one is the length of the array, passed as a const value.
	The third one is a function that will be called on every element of the array.
*/

template <typename T>
void func(T x)
{
	std::cout << "value " << x << std::endl;
}



template <typename T0, typename F>
void iter(T0 *array, const size_t length,  F function)
{
	(void)function;
	for (size_t i = 0; i < length; i++)
	{
		function(array[i]);
		//std::cout << addr[i] << std::endl;
	}
}	

#endif
