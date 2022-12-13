/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/14 17:32:29 by lrondia          ###   ########.fr       */
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
	
	try	{
		C109_36.beSigned(Ginette);
	}
	catch (const std::exception& e)	{
		std::cout << Ginette.getName() << e.what() << " to sign " << C109_36.getName() << "." << std::endl;
	}
	try	{
		F70bis.beSigned(Michel);
	}
	catch (const std::exception& e)	{
		std::cout << Michel.getName() << e.what() << " to sign " << F70bis.getName() << "." << std::endl;
	}
	
	Michel.signForm(shir6p4);
	Ginette.signForm(shir6p4);
	std::cout << std::endl << " | DESTRUCTORS | " << std::endl;
}