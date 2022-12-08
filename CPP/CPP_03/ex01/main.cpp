/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 19:25:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap George("George");
	ScavTrap Yasmine("Yasmine");

	std::cout << std::endl << "|  GUARD GATE  |" << std::endl;
	Yasmine.guardGate();
	
	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	Yasmine.attack("Margotelle");
	Yasmine.attack("romvan-d");
	
	std::cout << std::endl << "|  TAKE DAMAGE  |" << std::endl;
	Yasmine.takeDamage(6);
	Yasmine.takeDamage(60);
	
	std::cout << std::endl << "|  REPAIR  |" << std::endl;
	Yasmine.beRepaired(3);
	Yasmine.beRepaired(100);
	
	std::cout << std::endl << "|  TAKE DAMAGE  |" << std::endl;
	Yasmine.takeDamage(120);

	std::cout << std::endl << "|  REPAIR  |" << std::endl;
	Yasmine.beRepaired(3);

	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	Yasmine.attack("lol");
	std::cout << std::endl;
	return 0;
}
