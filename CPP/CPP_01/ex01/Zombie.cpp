/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:01:05 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/13 12:24:16 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Random zombie")	{
	std::cout << this->_name << " was created" << std::endl;
}

Zombie::Zombie(std::string name)	{
	this->_name = name;
	std::cout << this->_name << " was created" << std::endl;
}

Zombie::~Zombie(void)	{
	std::cout << this->_name << " has been destroyed" << std::endl;
}

void	Zombie::announce(void)	{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string	Zombie::getName(void)	{
	return _name;
}

void	Zombie::setName(std::string name)	{
	_name = name;
}
