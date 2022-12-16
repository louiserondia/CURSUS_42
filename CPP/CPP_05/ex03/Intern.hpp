/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 19:22:27 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/16 20:03:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <string.h>

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		Intern	&operator=(Intern const &rhs);
		~Intern(void);

		AForm	*makeForm(std::string form_name, std::string target);
		AForm	*newShrubberyCreationForm(std::string target);
		AForm	*newRobotomyRequestForm(std::string target);
		AForm	*newPresidentialPardonForm(std::string target);

	private:
		typedef AForm	*(Intern::*Fpointer)(std::string);
		Fpointer		_fpointer[3];
};

#endif
