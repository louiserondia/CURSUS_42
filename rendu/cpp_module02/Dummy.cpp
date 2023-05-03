/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:19:56 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 16:32:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

ATarget	*Dummy::clone() const { return new Dummy(); }
