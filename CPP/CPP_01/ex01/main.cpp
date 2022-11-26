/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:33:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/26 17:57:55 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)	{
	Zombie	*Horde = zombieHorde(3, "loulou");

	for (int i = 0; i < 3; i++)	{
		Horde[i].announce();
	}
	delete [] Horde;
	return (0);
}