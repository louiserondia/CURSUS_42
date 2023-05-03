/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:57:38 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 17:02:56 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (map::iterator it = _book.begin(); it != _book.end(); it++)
		delete it->second;
}

void	SpellBook::learnSpell(ASpell *spell) {
	_book.insert(std::make_pair(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(const std::string &spell) {
	_book.erase(spell);
}

ASpell	*SpellBook::createSpell(const std::string &spell) {
	map::iterator	res = _book.find(spell);

	if (res != _book.end())
		return res->second;
	return NULL;
}
