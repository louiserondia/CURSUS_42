/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:52:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/06 11:43:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) {
}

Point::~Point(void)	{
}

Point	&Point::operator=(const Point &rhs)	{
	(void) rhs;
	return *this;
}

const Fixed	Point::GetX(void) const	{
	return _x;
}

const Fixed	Point::GetY(void) const	{
	return _y;
}
