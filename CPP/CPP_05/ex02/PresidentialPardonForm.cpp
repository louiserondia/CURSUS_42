/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/15 16:23:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


//		CON/DESTRUCTORS

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Schrubbery", 25, 5), _target("Robotomy")	{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5), _target(target)	{
}

PresidentialPardonForm::~PresidentialPardonForm(void)	{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : _target(copy._target)	{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)	{
	AForm::operator=(rhs);
	_target = rhs._target;
	return *this;
}


//		MEMBER FUNCTIONS

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!checkExecution(executor))
		return false;
	std::cout << _target << " has been pardonned by its Majesty Zaphod Beeblebrox." << std::endl;
	return true;
}
