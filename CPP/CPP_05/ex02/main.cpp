/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/16 17:54:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)	{
	
	std::cout << std::endl << "	| CONSTRUCTORS |	" << std::endl;
	Bureaucrat					Random;
	Bureaucrat					Michel("Michel", 10);
	Bureaucrat					Ginette("Ginette", 2);
	ShrubberyCreationForm		F70bis("F70bis");
	RobotomyRequestForm			C109_36("C109/36");
	PresidentialPardonForm		Jesus("Jesus");
	
	std::cout << std::endl << "	| SIGNING AND EXECUTING |	" << std::endl;
	F70bis.execute(Ginette);
	Ginette.signForm(F70bis);
	Random.executeForm(F70bis);
	Ginette.executeForm(F70bis);
	Ginette.signForm(C109_36);
	Ginette.executeForm(C109_36);
	Michel.signForm(Jesus);
	Michel.executeForm(Jesus);
	Ginette.executeForm(Jesus);

	std::cout << std::endl << "	| DESTRUCTORS |	" << std::endl;
}