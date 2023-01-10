/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:02 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 11:15:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using namespace std;

Animal::Animal(void)	{
	type = "Random animal";
	cout << "Animal default constructor called" << endl;
}

Animal::~Animal()	{
	cout << "Animal default destructor called" << endl;
}

Animal::Animal(Animal const &copy)	{
	*this = copy;
	cout << "Animal copy constructor called" << endl;
}

Animal	&Animal::operator=(Animal const &rhs)	{
	type = rhs.type;
	return *this;
}

void	Animal::makeSound(void) const	{
	cout << "I am an animal hello" << endl;
	return;
}

std::string	Animal::getType(void) const	{
	return type;
}
