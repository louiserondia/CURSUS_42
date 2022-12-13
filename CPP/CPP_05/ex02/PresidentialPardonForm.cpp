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

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!isGradeCorrect(executor.getGrade(), "Executor's grade"))
		return ;
	try
	{
		if (!isSigned())
			throw (AForm::NotSignedException());
		if (executor.getGrade() > getGradeToExecute())
			throw (AForm::GradeTooLowException());
	}
	catch (AForm::GradeTooLowException low)	{
		std::cout << executor.getName() << low.what() << " to execute " << getName() << std::endl;
		return;
	}
	catch (AForm::NotSignedException not_signed)	{
		std::cout << getName() << not_signed.what() << std::endl;
		return;
	}
	std::cout << _target << " has been pardonned by its Majesty Zaphod Beeblebrox." << std::endl;
}

bool	PresidentialPardonForm::isGradeCorrect(int grade, std::string type) const
{
	try
	{
		if (grade < _gmax)
			throw (AForm::GradeTooHighException());
		else if (grade > _gmin)
			throw (AForm::GradeTooLowException());
		return true;
	}
	catch (AForm::GradeTooHighException high)
	{
		std::cout << getName() << type << high.what() << std::endl;
	}
	catch (AForm::GradeTooLowException low)
	{
		std::cout << getName() << type << low.what() << std::endl;
	}
	return false;
}

