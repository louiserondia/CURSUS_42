/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:33:40 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/30 12:33:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget
{

	public:

		BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

		ATarget	*clone() const { return new BrickWall; }

};
