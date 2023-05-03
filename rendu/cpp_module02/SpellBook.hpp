/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:55:33 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:59:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class	SpellBook {

	private:

		typedef	std::map<std::string, ASpell *>	map;

		map			_book;

		SpellBook(const SpellBook &);
		SpellBook &operator=(const SpellBook &);

	public:

		SpellBook();

		~SpellBook();

		void	learnSpell(ASpell *spell);

		void	forgetSpell(const std::string &spell);

		ASpell	*createSpell(const std::string &spell);
};
