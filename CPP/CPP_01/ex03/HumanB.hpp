/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:32:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/13 12:12:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	
	Weapon		*_weapon;
	std::string	_name;

public:

	HumanB(std::string N);
	~HumanB(void);

void	attack(void);
void	setWeapon(Weapon &NewWeapon);

};

#endif
