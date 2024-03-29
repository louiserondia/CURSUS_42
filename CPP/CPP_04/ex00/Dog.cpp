/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 16:18:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using namespace std;

Dog::Dog(void)	{
	type = "Dog";
	cout << "Dog default constructor called" << endl;
}

Dog::~Dog()	{
	cout << "Dog default destructor called" << endl;
}

Dog::Dog(Dog const &copy)	{
	*this = copy;
	cout << "Dog copy constructor called" << endl;
}

Dog	&Dog::operator=(Dog const &rhs)	{
	type = rhs.type;
	return *this;
}

void	Dog::makeSound(void) const	{
	cout << "Waf waf wouf!!!!" << endl;
}

std::string	Dog::getType(void) const	{
	return type;
}