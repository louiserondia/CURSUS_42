/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:33:15 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/28 14:31:48 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon) : _name(Name), _weapon(Weapon) {
}

HumanA::~HumanA(void)	{
}

void	HumanA::attack(void)	{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
