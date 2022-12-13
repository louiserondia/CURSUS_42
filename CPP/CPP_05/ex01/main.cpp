/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/13 19:33:29 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)	{
	
	std::cout << std::endl << " | CONSTRUCTORS | " << std::endl;
	Bureaucrat	Michel("Michel", 149);
	Bureaucrat	Ginette("Ginette", 2);
	Form		F70bis("F70bis", 10, 10);
	Form		C109_36("C109/36", 2, 2);
	Form		shir6p4("shir6p4", 2, 2);
	
	C109_36.beSigned(Ginette);
	F70bis.beSigned(Michel);
	Ginette.signForm(shir6p4);
	std::cout << std::endl << " | DESTRUCTORS | " << std::endl;
}