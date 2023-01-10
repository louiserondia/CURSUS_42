/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:47:38 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 15:51:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat	&operator=(Bureaucrat const &rhs);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

		class GradeTooHighException	: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException	: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		std::string const	_name;
		int					_grade;
		static const int	_gmax = 1;
		static const int	_gmin = 150;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

# endif
