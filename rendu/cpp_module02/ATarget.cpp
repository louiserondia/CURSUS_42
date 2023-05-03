/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:19:01 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:36:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(const std::string &type) : _type(type) {}

ATarget::~ATarget() {}

const std::string	&ATarget::getType() const { return _type; }

void	ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!\n";
}



