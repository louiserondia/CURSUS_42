/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:02:08 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 17:35:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

using namespace std;

DiamondTrap::DiamondTrap(string name) : ClapTrap(), ScavTrap(), FragTrap()	{
	_name = name;
	_max_hp = FragTrap::_max_hp;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = _name + "_clap_name";
	cout << "DiamondTrap " << _name << "'s constructor called" << endl;
}

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()	{
	_name = "DiamondTrap";
	_max_hp = FragTrap::_max_hp;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = _name + "_clap_name";
	cout << "DiamondTrap " << _name << "'s constructor called" << endl;
}

DiamondTrap::~DiamondTrap(void)	{
	cout << "DiamondTrap " << _name << "'s destructor called" << endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)	{
	*this = copy;
	cout << "DiamondTrap's copy constructor called" << endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)	{
	_name = rhs._name;
	ClapTrap::_name = _name + "_clap_name";
	_max_hp = rhs._max_hp;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void	DiamondTrap::whoAmI(void)	{
	cout << "I am " << _name << ", also called " << ClapTrap::_name << "." << endl;
}
