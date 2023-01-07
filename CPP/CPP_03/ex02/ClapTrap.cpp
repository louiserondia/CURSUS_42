/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:02:08 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 19:23:37 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using namespace std;


///////////// CON/DESTRUCTION /////////////

ClapTrap::ClapTrap(string name) : _name(name), _max_hp(10), _hitPoints(10), _energyPoints(10), _attackDamage(0)	{
	cout << "ClapTrap " << _name << "'s constructor called" << endl;
}

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)	{
	cout << "ClapTrap constructor called" << endl;
}

ClapTrap::~ClapTrap(void)	{
	cout << "ClapTrap " << _name << "'s destructor called" << endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)	{
	*this = copy;
	cout << "ClapTrap copy constructor called" << endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)	{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}


///////////////// ATTACK /////////////////

void	ClapTrap::attack(const string &target)	{
	if (_energyPoints == 0 || _hitPoints == 0)	{
		cout << "ClapTrap " << _name
			 << " is too tired/dead. It's unable to attack right now." << endl;
		return;
	}
	_energyPoints--;
	cout << "ClapTrap " << _name << " attacks " << target 
		 << ", causing " << _attackDamage << " point(s) of damage!" << endl;
}


////////////// TAKE DAMAGE ///////////////

void	ClapTrap::takeDamage(unsigned int amount)	{
	unsigned int	i;

	for (i = 0; i < amount; i++)	{
		_hitPoints --;
		if (_hitPoints <= 0)	{
			cout << "ClapTrap " << _name 
				 << " is already dead. It can't take no more damages but already lost "
				 << i + 1 << " hit point(s)." << endl;
			break;
		}
	}
	if (i == amount)
	cout << "ClapTrap " << _name << " is attacked ! It loses "
		 << amount << " hit point(s)! (" << _hitPoints << " left)"<< endl;
}


///////////////// REPAIR /////////////////

void	ClapTrap::beRepaired(unsigned int amount)	{
	unsigned int	i;

	if (_energyPoints <= 0)	{
		cout << "ClapTrap " << _name
			 << " is too tired. It's unable to recover right now." << endl;
		return;
	}
	if (_hitPoints <= 0)	{
		cout << "ClapTrap " << _name
			 << " is already dead. It can't resurect." << endl;
		return;
	}
	for (i = 0; i < amount; i++)	{
		if (_hitPoints >= _max_hp)	{
			cout << "ClapTrap " << _name
				 << " is full of hit points ! It can't get no more (it recovered " 
				 << i + 1 << " hit points)." << endl;
			break;
		}
		_hitPoints ++;
	}
	if (i != 0)
		_energyPoints--;
	if (i == amount)
		cout << "ClapTrap " << _name << " is being repaired. It recovers "
			 << i + 1 << " hit point(s)! (" << _hitPoints << " left)" << endl;
}

