/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:16:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/01 12:00:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook {

public:
			Phonebook(void);
			~Phonebook(void);
	void	Add(Phonebook *Phonebook);
	void	Search(Phonebook *Phonebook);
	
private:
	int				_index;
	Contact			_contact[8];

	// void			AddLoop(std::string str, std::string *Field);
	// std::cout << "Enter contact's first name : ";
	// getline(std::cin, input);
	// Contact.setFirstName(input);
	void			DisplayShortContact(class Contact Contact, int index);
	void			DisplayFullContact(class Contact Contact);
	void			IncrementIndex(int *index);
	Contact			FillContact(void);
	std::string		FormatContact(std::string source);
};


#endif
