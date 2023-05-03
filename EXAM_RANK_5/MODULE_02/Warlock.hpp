/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:20:41 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/01 14:31:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
	private:

		std::string						_name;
		std::string						_title;
		SpellBook						_spellBook;

		Warlock() {
			std::cout << ": This looks like another boring day.\n";
		}

		Warlock(const Warlock &other) : _name(other.getName()), _title(other.getTitle()) {
			std::cout << getName() << ": This looks like another boring day.\n";
		}
		
		Warlock	&operator=(const Warlock &other) {
			_name = other.getName();
			_title = other.getTitle();
			return *this;
		}
		
	public:

		Warlock(std::string name, std::string title) : _name(name), _title(title) {
			std::cout << getName() << ": This looks like another boring day.\n";
		}
		
		~Warlock() {
			std::cout << getName() << ": My job here is done!\n";
		}

		std::string	getName() const { return _name; }
		
		std::string	getTitle() const { return _title; }
		
		void	setTitle(const std::string &title) { _title = title; }
		
		void	introduce() const {
			std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!\n";
		}

		void	learnSpell(ASpell *spell) {
			_spellBook.learnSpell(spell);
		}

		void	forgetSpell(std::string spell) {
			_spellBook.forgetSpell(spell);
		}

		void	launchSpell(std::string spell, const ATarget &target) {
			_spellBook.createSpell(spell)->launch(target);
		}

};
