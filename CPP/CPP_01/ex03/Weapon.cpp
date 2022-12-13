/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:15:49 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/12 15:49:32 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::Weapon(void) {
}

Weapon::~Weapon(void)	{
}

std::string	Weapon::getType(void)	{
	std::string	&ref = _type;
	return (ref);
}

void	Weapon::setType(std::string	newtype)	{
	_type = newtype;
}
