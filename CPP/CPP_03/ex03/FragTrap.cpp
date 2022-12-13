/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:02:08 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/13 14:42:00 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

using namespace std;

FragTrap::FragTrap(string name) : ClapTrap(name)	{
	_max_hp = 100;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	cout << "FragTrap " << _name << "'s constructor called" << endl;
}

FragTrap::FragTrap() :	ClapTrap() {
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	cout << _name << "'s constructor called" << endl;
}

FragTrap::~FragTrap(void)	{
	cout << "FragTrap " << _name << "'s destructor called" << endl;
}

FragTrap::FragTrap(FragTrap const &copy)	{
	*this = copy;
	cout << "FragTrap's copy constructor called" << endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)	{
	_name = rhs._name;
	_max_hp = rhs._max_hp;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return *this;
}

void	FragTrap::highFiveGuys(void)	{
	cout << "FragTrap " << _name << " asks for a high five to its buddies." << endl;
}
