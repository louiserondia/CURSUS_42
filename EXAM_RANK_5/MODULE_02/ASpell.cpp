/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:55:24 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/29 22:55:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(const ASpell &other) : _name(other.getName()), _effects(other.getEffects()) {
	std::cout << getName() << ": This looks like another boring day.\n";
}

ASpell	&ASpell::operator=(const ASpell &other) {
	_name = other.getName();
	_effects = other.getEffects();
	return *this;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {}

ASpell::~ASpell() {}

void	ASpell::launch(const ATarget &target) const { target.getHitBySpell(*this); }

std::string	ASpell::getName() const { return _name; }
std::string	ASpell::getEffects() const { return _effects; }
