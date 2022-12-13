/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:15:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/12 15:49:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
private:
	
	std::string	_type;
	
public:

	Weapon(std::string type);
	Weapon(void);
	~Weapon(void);

	std::string	getType(void);
	void		setType(std::string	newtype);
	
};

#endif
