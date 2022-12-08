/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 20:17:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using namespace std;

Animal::Animal(void)	{
	cout << "Animal default constructor called" << endl;
}

Animal::~Animal()	{
	cout << "Animal default destructor called" << endl;
}

void	Animal::makeSound(void) const	{
	return;
}

std::string	Animal::getType(void) const	{
	return type;
}
