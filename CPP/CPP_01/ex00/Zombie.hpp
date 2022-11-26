/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:01:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/26 17:39:12 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie	{

private:
	std::string	_name;
	
public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
