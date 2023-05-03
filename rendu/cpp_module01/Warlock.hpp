/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:26:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:35:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class	Warlock {

	private:

		typedef	std::map<std::string, ASpell *>	map;

		std::string	_name;
		std::string	_title;
		map			_book;

		Warlock();
		Warlock(const Warlock &);
		Warlock &operator=(const Warlock &);

	public:

		Warlock(const std::string &name, const std::string &title);

		~Warlock();

		const std::string	&getName() const;
		const std::string	&getTitle() const;
		void		setTitle(const std::string &title);

		void		introduce() const;
		void	learnSpell(ASpell *spell);

		void	forgetSpell(std::string spell);

		void	launchSpell(std::string spell, const ATarget &target);
};

