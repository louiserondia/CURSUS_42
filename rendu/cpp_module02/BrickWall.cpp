/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:56 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:52:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

ATarget	*BrickWall::clone() const { return new BrickWall(); }
