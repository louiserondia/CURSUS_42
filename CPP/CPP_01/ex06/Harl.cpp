/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:55:00 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/29 18:38:42 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
}

Harl::~Harl(void)	{
}

void	Harl::debug(void)	{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl ;
}

void	Harl::info(void)	{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl ;
}

void	Harl::warning(void)	{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl ;
}

void	Harl::error(void)	{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl ;
}

int		compare(std::string	level, std::string comparison[4])	{
	for (int i = 0; i < 4; i++)	{
		if (level == comparison[i] && i != 4)
			return (i);
	}
	return (4);
}

void	Harl::complain(std::string level)	{

	std::string	comparison[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*functer[4])(void) = {	&Harl::debug, &Harl::info, &Harl::warning, &Harl::error	};

	switch (compare(level, comparison))	{
		case 0:
			std::cout << "[ " << comparison[0] << " ]" << std::endl;
			(this->*(functer[0]))();
			std::cout << std::endl;
		case 1:
			std::cout << "[ " << comparison[1] << " ]" << std::endl;
			(this->*(functer[1]))();
			std::cout << std::endl;
		case 2:
			std::cout << "[ " << comparison[2] << " ]" << std::endl;
			(this->*(functer[2]))();
			std::cout << std::endl;
		case 3:
			std::cout << "[ " << comparison[3] << " ]" << std::endl;
			(this->*(functer[3]))();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
