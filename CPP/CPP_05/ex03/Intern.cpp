/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:25:31 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/16 20:12:31 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//		CON/DESTRUCTORS

Intern::Intern(void)	{
	_fpointer[0] = &Intern::newShrubberyCreationForm;
	_fpointer[1] = &Intern::newRobotomyRequestForm;
	_fpointer[2] = &Intern::newPresidentialPardonForm;
}

Intern::~Intern(void)	{
}

Intern::Intern(Intern const &copy)	{
	*this = copy;
}

Intern	&Intern::operator=(Intern const &rhs)	{
	(void) rhs;
	return *this;
}

//		MEMBER FUNCTIONS

AForm	*Intern::makeForm(std::string form_name, std::string target)	{
	std::string	name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for (int i = 0; i < 3; i++)	{
		if (name[i] == form_name)
			return (this->*_fpointer[i])(target);
	}
	std::cout << "This form doesn't exist (" << form_name << ")." << std::endl;
	return __null;
}

AForm	*Intern::newShrubberyCreationForm(std::string target)	{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::newRobotomyRequestForm(std::string target)	{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::newPresidentialPardonForm(std::string target)	{
	return new PresidentialPardonForm(target);
}
