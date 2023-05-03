/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:39:57 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/01 14:11:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class SpellBook
{
	private:

		typedef std::map<std::string, ASpell *>	map;

		map	_book;

		SpellBook(const SpellBook &) {}
		
		SpellBook	&operator=(const SpellBook &) { return *this; }
		
	public:

		SpellBook() {}
		
		~SpellBook() { 
			for (map::iterator it = _book.begin(); it != _book.end(); it++)
				delete it->second;
		}

		void	learnSpell(ASpell *spell) {
			_book.insert(std::make_pair(spell->getName(), spell->clone()));
		}

		void	forgetSpell(std::string spell) {
			_book.erase(spell);
		}

		ASpell	*createSpell(const std::string &spell) {
			map::iterator	find = _book.find(spell);
			if (find != _book.end())
				return find->second;
			return NULL;
		}

};
