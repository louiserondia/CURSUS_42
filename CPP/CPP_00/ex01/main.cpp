/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:20:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/30 16:59:04 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	operations(std::string input, Phonebook *Phonebook)
{
	if (input == "ADD")	{
		Phonebook->Add(Phonebook);
	}
	else if (input == "SEARCH")
		Phonebook->Search(Phonebook);
	else if (input != "EXIT")
		std::cout << "Wrong command. Please try again." << std::endl;
}

int	main(void)
{
	std::string	input;

	Phonebook	Phonebook;
	for (int i = 0; input != "EXIT"; i++)
	{
		std::getline(std::cin, input);
		operations(input, &Phonebook);
	}
	return (0);
}