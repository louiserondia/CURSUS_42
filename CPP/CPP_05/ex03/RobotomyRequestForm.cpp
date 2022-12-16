/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/16 18:22:48 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


//		CON/DESTRUCTORS

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45), _target("Robotomy")	{
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

bool	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!checkExecution(executor))
		return false;
	srand(time(NULL));
	std::cout << "~~~     BbbbbbrrrRRRrrrVVVvrVBbbRBrrr   ~~~" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized by " << executor.getName() << "." << std::endl;
	}
	else {
		std::cout << executor.getName() << " failed to robotomize " << getName() << "." << std::endl;
	}
	return true;
}

