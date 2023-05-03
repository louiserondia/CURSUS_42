/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:18:56 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/30 12:18:56 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ASpell.hpp"

class Fireball : public ASpell
{
private:
	std::string	_name;
	std::string	_effects;

public:
	
	Fireball() : ASpell("Fireball", "burnt to a crisp") {}

	ASpell	*clone() const { return new Fireball(); }

};
