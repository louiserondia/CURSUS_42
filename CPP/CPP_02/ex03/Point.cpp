/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:52:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/02 20:17:51 by lrondia          ###   ########.fr       */
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

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	FullArea;
	Fixed	PAC;
	Fixed	PAB;
	Fixed	PBC;

	FullArea = a.GetX() * (b.GetY() - c.GetY()) + b.GetX() * (c.GetY() - a.GetY()) + c.GetX() * (a.GetY() - b.GetY());
	PAC = a.GetX() * (point.GetY() - c.GetY()) + point.GetX() * (c.GetY() - a.GetY()) + c.GetX() * (a.GetY() - point.GetY());
	PAB = a.GetX() * (b.GetY() - point.GetY()) + b.GetX() * (point.GetY() - a.GetY()) + point.GetX() * (a.GetY() - b.GetY());
	PBC = point.GetX() * (b.GetY() - c.GetY()) + b.GetX() * (c.GetY() - point.GetY()) + c.GetX() * (point.GetY() - b.GetY());

	if (PAC + PAB + PBC == FullArea)
		return true;
	return false;
}
