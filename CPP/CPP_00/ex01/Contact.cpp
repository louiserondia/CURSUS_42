/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:20:25 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/01 11:54:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)	{
	return ;
}

Contact::~Contact(void)	{
	return ;
}

std::string	Contact::getFirstName(void) const	{
	return _firstName;
}

std::string	Contact::getLastName(void) const	{
	return _lastName;
}

std::string	Contact::getNickname(void) const	{
	return _nickname;
}

std::string	Contact::getPhoneNumber(void) const	{
	return _phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const	{
	return _darkestSecret;
}

void		Contact::setFirstName(std::string src)	{
	_firstName = src;
}

void		Contact::setLastName(std::string src)	{
	_lastName = src;
}

void		Contact::setNickname(std::string src)	{
	_nickname = src;
}

void		Contact::setPhoneNumber(std::string src)	{
	_phoneNumber = src;
}

void		Contact::setDarkestSecret(std::string src)	{
	_darkestSecret = src;
}

