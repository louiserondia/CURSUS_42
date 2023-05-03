/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:09:00 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:17:09 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ASpell;

class	ATarget {

	private:

		std::string	_type;

		ATarget();
		ATarget(const ATarget &);
		ATarget &operator=(const ATarget &);

	public:

		ATarget(const std::string &type);

		virtual ~ATarget();

		virtual ATarget	*clone() const = 0;

		const std::string	&getType() const;

		void	getHitBySpell(const ASpell &spell) const;

};

#include "ASpell.hpp"
