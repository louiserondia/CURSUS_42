/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:48:51 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 16:03:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(Form const &copy);
		Form	&operator=(Form const &rhs);
		~Form(void);

		bool		test(int grade, std::string type);
		void		beSigned(Bureaucrat &b);
		std::string	getName(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;

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
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
		static const int	_gmax = 1;
		static const int	_gmin = 150;

};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif
