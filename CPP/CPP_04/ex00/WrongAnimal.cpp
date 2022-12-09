/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 16:25:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

using namespace std;

WrongAnimal::WrongAnimal(void)	{
	type = "Random wrong animal";
	cout << "WrongAnimal default constructor called" << endl;
}

WrongAnimal::~WrongAnimal()	{
	cout << "WrongAnimal default destructor called" << endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)	{
	*this = copy;
	cout << "WrongAnimal copy constructor called" << endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)	{
	type = rhs.type;
	return *this;
}

void	WrongAnimal::makeSound(void) const	{
	cout << "I am an animal hello" << endl;
	return;
}

std::string	WrongAnimal::getType(void) const	{
	return type;
}
