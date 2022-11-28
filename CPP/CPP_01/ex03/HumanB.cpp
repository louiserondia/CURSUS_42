/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:33:15 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/28 14:47:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string N) : _name(N)	{
	_weapon = new Weapon(_weapon->getType());
}


HumanB::~HumanB(void)	{
}

void	HumanB::attack(void)	{
	std::cout << _name << " attacks with their ";
	if (_weapon->getType() != "")
		std::cout << _weapon->getType() << std::endl;
	else
		std::cout << "bare hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &NewWeapon)	{
	_weapon = &NewWeapon;
}

