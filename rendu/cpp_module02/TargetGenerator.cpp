/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:07:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 17:09:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {}

void	TargetGenerator::learnTargetType(ATarget *target) {
	_book.insert(std::make_pair(target->getType(), target));
}

void	TargetGenerator::forgetTargetType(const std::string &target) {
	_book.erase(target);
}

ATarget	*TargetGenerator::createTarget(const std::string &target) {
	map::iterator	res = _book.find(target);

	if (res != _book.end())
		return res->second;
	return NULL;
}
