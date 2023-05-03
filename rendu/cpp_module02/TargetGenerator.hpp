/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:05:32 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 17:07:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class	TargetGenerator {

	private:

		typedef	std::map<std::string, ATarget *>	map;

		map			_book;

		TargetGenerator(const TargetGenerator &);
		TargetGenerator &operator=(const TargetGenerator &);

	public:

		TargetGenerator();

		~TargetGenerator();

		void	learnTargetType(ATarget *target);

		void	forgetTargetType(const std::string &target);

		ATarget	*createTarget(const std::string &target);
};
