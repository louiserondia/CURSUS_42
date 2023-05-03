/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:03:52 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:16:59 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ATarget.hpp" 

class	ATarget;

class	ASpell {

	private:

		std::string	_name;
		std::string	_effects;

		ASpell();
		ASpell(const ASpell &);
		ASpell &operator=(const ASpell &);

	public:

		ASpell(const std::string &name, const std::string &effects);

		virtual ~ASpell();

		virtual ASpell	*clone() const = 0;

		const std::string	&getName() const;
		const std::string	&getEffects() const;
		
		void	launch(const ATarget &target) const;
};
