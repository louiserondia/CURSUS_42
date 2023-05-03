/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:55:24 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/29 22:55:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:

		std::string	_type;

		ATarget() {}

	public:

		ATarget(std::string type) : _type(type) {}

		ATarget(const ATarget &other) : _type(other.getType()) {}

		ATarget	&operator=(const ATarget &other) {
			_type = other.getType();
			return *this;
		}
		
		virtual ATarget	*clone() const = 0;

		virtual	~ATarget() {}

		void	getHitBySpell(const ASpell &spell) const {
			std::cout << getType() << " has been " << spell.getEffects() << "!\n";
		}

		std::string	getType() const { return _type; }

};
