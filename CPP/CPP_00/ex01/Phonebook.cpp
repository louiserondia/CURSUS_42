/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:21:11 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/23 16:16:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)	{
	this->index = 0;
	return ;
}

Phonebook::~Phonebook(void)	{
	return ;
}

void	Phonebook::DisplayContact(class Contact *Contact, int index)
{
	std::string	copy;

	copy = Contact->FirstName;
	copy.resize(10);
	if (Contact->FirstName.length() > 9)
		copy[9] = '.';
	// else if (Contact->FirstName.length() < 9)
	// {
		
	// }
	// std::cout << "Contact n°" << index << std::endl;
	std::cout << copy << " | ";
	std::cout << Contact->LastName << " | ";
	std::cout << Contact->Nickname << " | ";
	std::cout << Contact->PhoneNumber << " | ";
	std::cout <<Contact->DarkestSecret << std::endl;
	std::cout << std::endl;
}

void	Phonebook::AddLoop(std::string str, std::string *Field)
{
	std::string	input;

	std::cout << str;
	getline(std::cin, input);
	*Field = input;
}

void	Phonebook::Add(Phonebook *Phonebook, class Contact *Contact)
{
	std::string	input[5];

	while (Contact->FirstName == ""){
		Phonebook->AddLoop("Enter contact's first name : ", &Contact->FirstName);
	}
	while (Contact->LastName == "")	{
		Phonebook->AddLoop("Enter contact's last name : ", &Contact->LastName);
	}	
	while (Contact->Nickname == "")	{
		Phonebook->AddLoop("Enter contact's nickname : ", &Contact->Nickname);
	}
	while (Contact->PhoneNumber == "")	{
		Phonebook->AddLoop("Enter contact's phone number : ", &Contact->PhoneNumber);
	}
	while (Contact->DarkestSecret == "")	{
		Phonebook->AddLoop("Enter contact's darkest secret : ", &Contact->DarkestSecret);
	}
	std::cout << "Contact added correctly" << std::endl;
	Phonebook->DisplayContact(Contact, Phonebook->index);
	Phonebook->index++;
	if (Phonebook->index > 8)
		Phonebook->index = 0;
}
