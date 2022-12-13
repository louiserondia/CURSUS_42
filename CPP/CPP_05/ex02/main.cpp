/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/15 18:12:48 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)	{
	
	std::cout << std::endl << " | CONSTRUCTORS | " << std::endl;
	Bureaucrat					Random;
	Bureaucrat					Michel("Michel", 10);
	Bureaucrat					Ginette("Ginette", 2);
	ShrubberyCreationForm		F70bis("F70bis");
	RobotomyRequestForm			C109_36("C109/36");
	PresidentialPardonForm		Jesus("Jesus");
	
	F70bis.execute(Random);
	F70bis.execute(Ginette);
	Ginette.signForm(F70bis);
	F70bis.execute(Ginette);
	Ginette.signForm(C109_36);
	C109_36.execute(Ginette);
	C109_36.execute(Ginette);
	C109_36.execute(Ginette);
	Michel.signForm(Jesus);
	Jesus.execute(Michel);
	Jesus.execute(Ginette);
	std::cout << std::endl << " | DESTRUCTORS | " << std::endl;
}