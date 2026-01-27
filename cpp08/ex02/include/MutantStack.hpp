/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhavari <mkhavari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:12:26 by mkhavari          #+#    #+#             */
/*   Updated: 2025/11/27 13:12:29 by mkhavari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_hpp
# define MutantStack_hpp

#include <iostream>
#include <vector>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{ // it should use from the std::stakc and its container
	private:
		// std::vector<T> data; // vector of any type can be, determin at compile-time
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack &other);
		
		MutantStack& operator=(const MutantStack &other);

		typedef typename std::stack<T>::container_type::iterator iterator; //points to its internal container
		typedef typename std::stack<T>::container_type::const_iterator const_iterator; //points to its internal container
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator; //points to its internal container
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator; //points to its internal container


	iterator begin();
	iterator end();

	const_iterator begin() const;
	const_iterator end() const;

	reverse_iterator rbegin();
	reverse_iterator rend();

	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;

};

#include "MutantStack.tpp"
#endif
