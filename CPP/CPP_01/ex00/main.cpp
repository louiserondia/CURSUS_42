/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:33:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/26 17:47:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)	{
	Zombie	*Louise;
	Zombie	*Greg = newZombie("Greg");
	Zombie	Prout = Zombie("Prout");

	randomChump("Yacine");
	randomChump("Johanna");
	delete (Greg);
	Louise = newZombie("Louise");
	Louise->announce();
	Prout.announce();
	delete (Louise);
	return (0);
}