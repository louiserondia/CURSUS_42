/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:16:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/26 13:58:17 by lrondia          ###   ########.fr       */
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

	int				index;
	Contact			Contact[8];

					Phonebook(void);
					~Phonebook(void);
	class Contact	Add(Phonebook *Phonebook);
	void			Search(Phonebook *Phonebook);
	void			IncrementIndex(int *index);
	
private:

	void			AddLoop(std::string str, std::string *Field);
	void			DisplayShortContact(class Contact Contact, int index);
	void			DisplayFullContact(class Contact Contact, int index);
	std::string		FormatContact(std::string source);
};


#endif
