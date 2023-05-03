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

#pragma once

#include <iostream>

class ATarget;

class ASpell
{
	protected:

		std::string	_name;
		std::string	_effects;

	public:

		ASpell();
		
		ASpell(const ASpell &other);
		
		ASpell	&operator=(const ASpell &other);
		
		ASpell(std::string name, std::string effects);
		
		virtual ASpell	*clone() const = 0;
		
		virtual	~ASpell();

		void	launch(const ATarget &target) const;

		std::string	getName() const;
		std::string	getEffects() const;

};

#include "ATarget.hpp"
