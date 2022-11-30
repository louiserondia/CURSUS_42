/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:21:11 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/30 12:15:02 by lrondia          ###   ########.fr       */
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

void	Phonebook::IncrementIndex(int *index)	{
	(*index)++;
	if (*index >= 8)
		*index = 0;
}

std::string	Phonebook::FormatContact(std::string source)
{
	std::string	copy;

	copy = source;
	if (copy.length() > 9)
	{
		copy.resize(10);
		copy[9] = '.';
	}
	while (copy.length() < 10)
	{
		copy.insert(0, " ");
	}
	return (copy);
}

void	Phonebook::DisplayShortContact(class Contact Contact, int index)
{
	std::cout << FormatContact(std::to_string(index)) << " | ";
	std::cout << FormatContact(Contact.FirstName) << " | ";
	std::cout << FormatContact(Contact.LastName) << " | ";
	std::cout << FormatContact(Contact.Nickname) << std::endl;
}

void	Phonebook::DisplayFullContact(class Contact Contact)
{
	std::cout << "First name :		" << Contact.FirstName << std::endl;
	std::cout << "Last name :		" << Contact.LastName << std::endl;
	std::cout << "Nickname :		" << Contact.Nickname << std::endl;
	std::cout << "Phone number :		" << Contact.PhoneNumber << std::endl;
	std::cout << "Darkest secret :	" << Contact.DarkestSecret << std::endl;
}

void	Phonebook::AddLoop(std::string str, std::string *Field)
{
	std::string	input;

	std::cout << str;
	getline(std::cin, input);
	*Field = input;
}

void	Phonebook::Search(Phonebook *Phonebook)
{
	std::string	input;
	int			index;

	index = -1;
	for (int i = 0; i < 8; i++)
	{
		if (Phonebook->Contact[i].FirstName != "")
			DisplayShortContact(Phonebook->Contact[i], i);
	}
	std::cout << std::endl;
	while (index < 0 || index >= 8 || Phonebook->Contact[index].FirstName == "")
	{
		std::cout << "Insert the index of the contact you wish to see : ";
		getline(std::cin, input);
		if (isdigit(input[0]) && input.length() == 1)
			index = stoi(input);
		if (index < 0 || index >= 8)
			std::cout << "Wrong input (index must be a number between 0 and 7). Please try again." << std::endl;
		else if (Phonebook->Contact[index].FirstName == "")
			std::cout << "This contact doesn't exit. Please try again." << std::endl;
		else
			DisplayFullContact(Phonebook->Contact[index]);
		std::cout << std::endl;
	}
}

Contact	Phonebook::Add(Phonebook *Phonebook)
{
	class Contact Contact;
	std::string	input[5];

	while (Contact.FirstName == ""){
		Phonebook->AddLoop("Enter contact's first name : ", &Contact.FirstName);
	}
	while (Contact.LastName == "")	{
		Phonebook->AddLoop("Enter contact's last name : ", &Contact.LastName);
	}	
	while (Contact.Nickname == "")	{
		Phonebook->AddLoop("Enter contact's nickname : ", &Contact.Nickname);
	}
	while (Contact.PhoneNumber == "")	{
		Phonebook->AddLoop("Enter contact's phone number : ", &Contact.PhoneNumber);
	}
	while (Contact.DarkestSecret == "")	{
		Phonebook->AddLoop("Enter contact's darkest secret : ", &Contact.DarkestSecret);
	}
	std::cout << "Contact added correctly" << std::endl << std::endl;
	return (Contact);
}
