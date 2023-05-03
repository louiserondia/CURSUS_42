/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:49 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:53:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ASpell.hpp" 

class	Fireball : public ASpell {

	public:

		Fireball();

		~Fireball();

		ASpell	*clone() const;

};
