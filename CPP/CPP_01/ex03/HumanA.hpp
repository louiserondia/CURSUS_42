/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:32:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/28 14:15:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:

	Weapon		&_weapon;
	std::string	_name;
	
public:

	HumanA(std::string N, Weapon &Weapon);
	~HumanA(void);

void	attack(void);

};

#endif
