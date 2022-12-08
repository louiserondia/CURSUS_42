/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 20:17:04 by lrondia          ###   ########.fr       */
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

void	Dog::makeSound(void) const	{
	cout << "Barwf !!!! (dog sound)" << endl;
}

std::string	Dog::getType(void) const	{
	return type;
}