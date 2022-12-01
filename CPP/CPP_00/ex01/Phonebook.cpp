/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:21:11 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/01 11:54:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(void)	{
	this->_index = 0;
	return ;
}

Phonebook::~Phonebook(void)	{
	return ;
}

void	Phonebook::IncrementIndex(int *_index)	{
	(*_index)++;
	if (*_index >= 8)
		*_index = 0;
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
	std::cout << FormatContact(Contact.getFirstName()) << " | ";
	std::cout << FormatContact(Contact.getLastName()) << " | ";
	std::cout << FormatContact(Contact.getNickname()) << std::endl;
}

void	Phonebook::DisplayFullContact(class Contact Contact)
{
	std::cout << "First name :		" << Contact.getFirstName() << std::endl;
	std::cout << "Last name :		" << Contact.getLastName() << std::endl;
	std::cout << "Nickname :		" << Contact.getNickname() << std::endl;
	std::cout << "Phone number :		" << Contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret :	" << Contact.getDarkestSecret() << std::endl;
}

void	Phonebook::Search(Phonebook *Phonebook)
{
	std::string	input;
	int			index;

	index = -1;
	for (int i = 0; i < 8; i++)
	{
		if (Phonebook->_contact[i].getFirstName() != "")
			DisplayShortContact(Phonebook->_contact[i], i);
	}
	std::cout << std::endl;
	while (index < 0 || index >= 8 || Phonebook->_contact[index].getFirstName() == "")
	{
		std::cout << "Insert the index of the contact you wish to see : ";
		getline(std::cin, input);
		if (isdigit(input[0]) && input.length() == 1)
			index = stoi(input);
		if (index < 0 || index >= 8)
			std::cout << "Wrong input (index must be a number between 0 and 7). Please try again." << std::endl;
		else if (Phonebook->_contact[index].getFirstName() == "")
			std::cout << "This contact doesn't exit. Please try again." << std::endl;
		else
			DisplayFullContact(Phonebook->_contact[index]);
		std::cout << std::endl;
	}
}

std::string	AddLoop(std::string str)
{
	std::string	input;

	std::cout << str;
	getline(std::cin, input);
	return (input);
}

Contact	Phonebook::FillContact(void)	{
	std::string	input;
	class Contact Contact;

	while (Contact.getFirstName() == ""){
		Contact.setFirstName(AddLoop("Enter contact's first name : "));
	}
	while (Contact.getLastName() == "")	{
		Contact.setLastName(AddLoop("Enter contact's last name : "));
	}	
	while (Contact.getNickname() == "")	{
		Contact.setNickname(AddLoop("Enter contact's nickname : "));
	}
	while (Contact.getPhoneNumber() == "")	{
		Contact.setPhoneNumber(AddLoop("Enter contact's phone number : "));
	}
	while (Contact.getDarkestSecret() == "")	{
		Contact.setDarkestSecret(AddLoop("Enter contact's darkest secret : "));
	}
	std::cout << "Contact added correctly" << std::endl << std::endl;
	return (Contact);
}

void	Phonebook::Add(Phonebook *Phonebook)	{
	Phonebook->_contact[Phonebook->_index] = Phonebook->FillContact();
	Phonebook->IncrementIndex(&Phonebook->_index);
}
