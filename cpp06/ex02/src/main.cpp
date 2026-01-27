/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:17:54 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:25:20 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

int main()
{
	std::cout << "identify with *: \n";
	Base* p = generate();
	identify(p);
		
	std::cout << "\n\nidentify with &: \n";
	Base &ref = *p;
	identify(ref);
}