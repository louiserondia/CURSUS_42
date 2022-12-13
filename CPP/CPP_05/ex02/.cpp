/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/15 16:23:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


//		CON/DESTRUCTORS

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Schrubbery", 72, 45), _target("Robotomy")	{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), _target(target)	{
}

RobotomyRequestForm::~RobotomyRequestForm(void)	{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : _target(copy._target)	{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)	{
	AForm::operator=(rhs);
	_target = rhs._target;
	return *this;
}


//		MEMBER FUNCTIONS

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
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
	std::cout << "~~~	BbbbbbrrrRRRrrrVVVvrVBbbRBrrr	~~~" << std::endl;
	if (std::rand() % 2)
		std::cout << executor.getName() << " failed to robotomise " << _target << "." << std::endl;
	else
		std::cout << _target << " was correctly robotomised by " << executor.getName() << "." << std::endl;
}

bool	RobotomyRequestForm::isGradeCorrect(int grade, std::string type) const
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

