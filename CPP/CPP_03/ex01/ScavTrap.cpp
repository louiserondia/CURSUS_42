/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:02:08 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 19:09:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using namespace std;

ScavTrap::ScavTrap(string name) : ClapTrap(name)	{
	_max_hp = 100;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	cout << "ScavTrap " << _name << "'s constructor called" << endl;
}

ScavTrap::ScavTrap() :	ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	cout << "ScavTrap " << _name << "'s constructor called" << endl;
}

ScavTrap::~ScavTrap(void)	{
	cout << "ScavTrap " << _name << "'s destructor called" << endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)	{
	*this = copy;
	cout << "ScavTrap's copy constructor called" << endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)	{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void	ScavTrap::attack(const string &target)	{
	if (_energyPoints == 0 || _hitPoints == 0)	{
		cout << "ClapTrap " << _name
			 << " is too tired/dead. It's unable to attack right now." << endl;
		return;
	}
	_energyPoints--;
	cout << "ScavTrap " << _name << " attacks " << target 
		 << ", causing " << _attackDamage << " point(s) of damage!" << endl;
}

void	ScavTrap::guardGate(void)	{
	cout << "ScavTrap " << _name << " has entered Gate Keeper mode." << endl;
}
