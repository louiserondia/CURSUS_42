/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:16:44 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/24 12:22:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "Contact.hpp"

class Phonebook {

public:
	Phonebook(void);
	~Phonebook(void);

	int		index;
	Contact	Contact[8];

	class Contact	Add(Phonebook *Phonebook);
	void			Search(Phonebook *Phonebook);
	void			AddLoop(std::string str, std::string *Field);
	void			DisplayContact(class Contact Contact, int index);
	std::string		FormatContact(std::string source);
	void			IncrementIndex(int *index);
};


#endif
