/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/16 18:20:57 by lrondia          ###   ########.fr       */
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

bool	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!checkExecution(executor))
		return false;
	std::ofstream	ofs(_target + "_shrubbery");
	ofs << _tree;
	return true;
}
