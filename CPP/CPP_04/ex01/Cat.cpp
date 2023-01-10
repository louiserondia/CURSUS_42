/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:02 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 13:13:22 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using namespace std;

Cat::Cat(void)	{
	type = "Cat";
	cout << "Cat default constructor called" << endl;
	_brain = new Brain();
}

Cat::~Cat()	{
	delete _brain;
	cout << "Cat default destructor called" << endl;
}

Cat::Cat(Cat const &copy)	{
	*this = copy;
	cout << "Cat copy constructor called" << endl;
}

Cat	&Cat::operator=(Cat const &rhs)	{
	type = rhs.type;
	return *this;
}

void	Cat::makeSound(void) const	{
	cout << "Miiaaaaouuuuuuu mi mi mi i am a cutie" << endl;
}

std::string	Cat::getType(void) const	{
	return type;
}

Brain	&Cat::getBrain(void)	{
	return *_brain;
}
