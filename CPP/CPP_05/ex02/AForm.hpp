/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:48:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/15 12:31:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		AForm(AForm const &copy);
		AForm	&operator=(AForm const &rhs);
		~AForm(void);

		virtual bool		isGradeCorrect(int grade, std::string type) const ;
		void				beSigned(Bureaucrat &b);
		std::string			getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		virtual void		execute(Bureaucrat const &executor) const = 0;
		bool				isSigned(void) const;

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

		class NotSignedException : public std::exception {
       		public:
				virtual const char	*what() const throw();
    	};

	private:
		const std::string	_name;
		bool				_is_signed;
		int					_grade_to_sign;
		int					_grade_to_execute;
		static const int	_gmax = 1;
		static const int	_gmin = 150;

};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
