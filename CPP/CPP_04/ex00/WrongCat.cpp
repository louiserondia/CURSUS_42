/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 16:15:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

using namespace std;

WrongCat::WrongCat(void) : WrongAnimal()	{
	type = "Wrong cat";
	cout << "WrongCat default constructor called" << endl;
}

WrongCat::~WrongCat()	{
	cout << "WrongCat default destructor called" << endl;
}

WrongCat::WrongCat(WrongCat const &copy)	{
	*this = copy;
	cout << "WrongCat copy constructor called" << endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)	{
	type = rhs.type;
	return *this;
}

void	WrongCat::makeSound(void) const	{
	cout << "Wrong noise mi mi mouuuu brbrbeee" << endl;
}

std::string	WrongCat::getType(void) const	{
	return type;
}
