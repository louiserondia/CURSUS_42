/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:11:49 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:32:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ASpell.hpp" 

class	Fwoosh : public ASpell {

	public:

		Fwoosh();

		~Fwoosh();

		ASpell	*clone() const;

};
