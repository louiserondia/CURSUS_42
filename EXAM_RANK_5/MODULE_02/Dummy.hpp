/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:33:40 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/30 12:33:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"

class Dummy : public ATarget
{

	public:

		Dummy() : ATarget("Target Practice Dummy") {}
		
		ATarget	*clone() const { return new Dummy; }

};
