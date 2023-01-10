/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 17:14:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main(void)	{
	Intern intern;
	Intern someRandomIntern;
	AForm* rrf;
	
	std::cout << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "Blop");
	std::cout << std::endl << intern.makeForm("robotomy request", "Bender")->getGradeToExecute() << std::endl;
	std::cout << std::endl << intern.makeForm("presidential pardon", "2nd Bender")->getGradeToSign() << std::endl << std::endl;
	intern.makeForm("shrubbery creation", "Other form");
	intern.makeForm("shrubbery2 creation", "Last form");
}