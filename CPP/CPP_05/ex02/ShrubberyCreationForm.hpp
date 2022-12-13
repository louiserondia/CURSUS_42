/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:38:48 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/15 16:13:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm(void);

		bool	isGradeCorrect(int grade, std::string type) const;
		void	execute(Bureaucrat const &executor) const;

	private:
		std::string					_target;
		static const std::string	_tree;
		static const int			_gmax = 1;
		static const int			_gmin = 150;
};

#endif
