/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/13 17:47:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)	{
	
	std::cout << std::endl << " | CONSTRUCTORS | " << std::endl;
	Bureaucrat	Random;
	Bureaucrat	Michel("Michel", 149);
	Bureaucrat	Ginette("Ginette", 2);
	Bureaucrat	John(Ginette);
	Bureaucrat	Fail("Failure", 180);

	std::cout << std::endl << " | IN/DECREMENTATION | " << std::endl;
	Ginette.incrementGrade();
	Ginette.incrementGrade();
	Michel.decrementGrade();
	Michel.decrementGrade();
	Fail.incrementGrade();

	std::cout << std::endl << " | PRESENTATION | " << std::endl;
	std::cout << "John is actually : " << John;
	std::cout << "Ginette is now : " << Ginette;
	std::cout << "Michel is : " << Michel;
	std::cout << "Fail is just a " << Fail;
	std::cout << "And the random dude is still : " << Random;
	
	std::cout << std::endl << " | DESTRUCTORS | " << std::endl;
}