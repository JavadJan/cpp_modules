/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:25:24 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 19:05:08 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

int main()
{
	std::cout << "\033[1;33m[TEST1: ] -----Array of Integer -----\033[0m" << std::endl;
	int arr[3] = {10, 11, 9};
	iter(arr, 3, func<int>);
	
	std::cout << "\033[1;33m[TEST2: ] -----Array of string -----\033[0m" << std::endl;
	const char *str[3] = {"Javad", "John", "Alex"};
	iter(str, 3, func<const char *>);
	
	std::cout << "\033[1;33m[TEST3: ] -----Array of float -----\033[0m" << std::endl;
	float f[3] = {10.10f, 11.11f, 9.9f};
	iter(f, 3, func<float>);
	
	std::cout << "\033[1;33m[TEST4: ] -----Array of double -----\033[0m" << std::endl;
	double d[3] = {10.10, 11.11, 9.9};
	iter(d, 3, func<double>);
}

