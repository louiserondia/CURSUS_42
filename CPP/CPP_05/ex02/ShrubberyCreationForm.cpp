/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/15 18:11:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::_tree =
"          .     .  .      +     .      .          .\n"
"     .       .      .     #       .           .\n"
"        .      .         ###            .      .      .\n"
"      .      .   '#:. .:##'##:. .:#'  .      .\n"
"          .      . '####'###'####'  .\n"
"       .     '#:.    .:#'###'#:.    .:#'  .        .       .\n"
"  .             '#########'#########'        .        .\n"
"        .    '#:.  '####'###'####'  .:#'   .       .\n"
"     .     .  '#######'##'##'#######'                  .\n"
"                .'##'#####'#####'##'           .      .\n"
"    .   '#:. ...  .:##'###'###'##:.  ... .:#'     .\n"
"      .     '#######'##'#####'##'#######'      .     .\n"
"    .    .     '#####'#######'#####'    .      .\n"
"            .     '      000      '    .     .'\n"
"       .         .   .   000     .        .       .\n"
".. .. ..................O000O.................. .... ..";


//		CON/DESTRUCTORS

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Schrubbery", 145, 137), _target("Shrubbery")	{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137), _target(target)	{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)	{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : _target(copy._target)	{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)	{
	AForm::operator=(rhs);
	_target = rhs._target;
	return *this;
}


//		MEMBER FUNCTIONS

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
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

	std::ofstream	ofs(_target + "_shrubbery");
	ofs << _tree;
	std::cout << getName() << " was correctly executed by " << executor.getName() << "." << std::endl;
}

bool	ShrubberyCreationForm::isGradeCorrect(int grade, std::string type) const
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

