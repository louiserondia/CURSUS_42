/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/16 20:13:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)	{
	Intern intern;

	std::cout << intern.makeForm("robotomy request", "Bender")->getGradeToExecute() << std::endl;
	std::cout << intern.makeForm("presidential pardon", "Bender")->getGradeToSign() << std::endl;
	intern.makeForm("shrubbery creation", "Bender");
	intern.makeForm("shrubbery2 creation", "Bender");
}