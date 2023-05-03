/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:26:18 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 17:05:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string &name, const std::string &title) : _name(name), _title(title) {
			std::cout << _name << ": This looks like another boring day.\n";
		}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!\n";
}

const std::string	&Warlock::getName() const { return _name; }
const std::string	&Warlock::getTitle() const { return _title; }
void		Warlock::setTitle(const std::string &title) { _title = title; }

void		Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

void	Warlock::learnSpell(ASpell *spell) {
	_book.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell) {
	_book.forgetSpell(spell);
}

void	Warlock::launchSpell(std::string spell, const ATarget &target) {
	_book.createSpell(spell)->launch(target);
}

