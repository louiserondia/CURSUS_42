/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:20:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/24 13:23:07 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	operations(std::string input, Phonebook *Phonebook)
{
	if (input == "ADD")
	{
		Phonebook->Contact[Phonebook->index] = Phonebook->Add(Phonebook);
		Phonebook->IncrementIndex(&Phonebook->index);
	}
	else if (input == "SEARCH")
		Phonebook->Search(Phonebook);
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