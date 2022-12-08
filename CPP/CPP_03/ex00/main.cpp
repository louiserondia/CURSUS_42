/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 15:05:53 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap George("George");

	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	George.attack("Yann");
	George.attack("romvan-d");
	
	std::cout << std::endl << "|  TAKE DAMAGE  |" << std::endl;
	George.takeDamage(6);
	
	std::cout << std::endl << "|  REPAIR  |" << std::endl;
	George.beRepaired(3);
	George.beRepaired(3);
	George.beRepaired(3);
	
	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	George.attack("prout");
	George.attack("prout");
	George.attack("prout");
	George.attack("prout");
	George.attack("prout");
	George.attack("prout");
	George.attack("prout");
	
	std::cout << std::endl << "|  TAKE DAMAGE  |" << std::endl;
	George.takeDamage(16);

	std::cout << std::endl << "|  REPAIR  |" << std::endl;
	George.beRepaired(3);

	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	George.attack("lol");
	std::cout << std::endl;
	return 0;
}
