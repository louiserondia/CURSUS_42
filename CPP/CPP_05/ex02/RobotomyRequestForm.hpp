/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:11:22 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/15 17:14:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);
		~RobotomyRequestForm(void);

		bool	isGradeCorrect(int grade, std::string type) const;
		void	execute(Bureaucrat const &executor) const;

	private:
		std::string					_target;
		static const int			_gmax = 1;
		static const int			_gmin = 150;
};

#endif
