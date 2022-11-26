/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:19:00 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/26 17:40:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)	{
	Zombie	*NewZombie	= new Zombie(name);
	return (NewZombie);
}
