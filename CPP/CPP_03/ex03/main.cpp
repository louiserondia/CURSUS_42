/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 19:26:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap	John("John");

	std::cout << std::endl << "|  WHO AM I  |" << std::endl;
	John.whoAmI();
	
	std::cout << std::endl << "|  ATTACK  |" << std::endl;
	John.attack("Margotelle");
	John.attack("romvan-d");
	
	std::cout << std::endl << "|  TAKE DAMAGE  |" << std::endl;
	John.takeDamage(120);

	std::cout << std::endl;
	return 0;
}
