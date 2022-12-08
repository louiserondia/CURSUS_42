/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 19:25:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {
	ClapTrap George("George");
	ScavTrap Yasmine("Yasmine");
	FragTrap Margotelle("Margotelle");

	std::cout << std::endl << "|  HIGH FIVE  |" << std::endl;
	Margotelle.highFiveGuys();
	
	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	Margotelle.attack("Margotelle");
	Margotelle.attack("romvan-d");
	
	std::cout << std::endl << "|  TAKE DAMAGE  |" << std::endl;
	Margotelle.takeDamage(6);
	Margotelle.takeDamage(60);
	
	std::cout << std::endl << "|  REPAIR  |" << std::endl;
	Margotelle.beRepaired(3);
	Margotelle.beRepaired(100);
	
	std::cout << std::endl << "|  TAKE DAMAGE  |" << std::endl;
	Margotelle.takeDamage(120);

	std::cout << std::endl << "|  REPAIR  |" << std::endl;
	Margotelle.beRepaired(3);

	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	Margotelle.attack("lol");
	std::cout << std::endl;
	return 0;
}
