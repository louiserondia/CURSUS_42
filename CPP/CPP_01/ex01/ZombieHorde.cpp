/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:51:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/26 17:55:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)	{
	Zombie	*ZombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)	{
		ZombieHorde[i] = Zombie(name);
	}
	return (ZombieHorde);
}
