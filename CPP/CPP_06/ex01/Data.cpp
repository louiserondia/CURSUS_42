/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:25:10 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/29 15:43:14 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void)	{
}

Data::Data(Data const &src) : s(src.s) {
}

Data::~Data(void)	{
}

Data	&Data::operator=(Data const &rhs)	{
	this->s = rhs.s;
	return *this;
}

uintptr_t	serialize(Data *ptr)	{
		return reinterpret_cast<uintptr_t>(ptr);
}

Data		*deserialize(uintptr_t raw)	{
		return reinterpret_cast<Data *>(raw);
}
