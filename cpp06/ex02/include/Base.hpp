/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:17:42 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/26 13:28:22 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <typeinfo>  // for std::bad_cast

class Base {
	public:
		virtual ~Base(); // declaration only
};
Base *generate(void);
void identify(Base* p);
void identify(Base &ref);

#endif
