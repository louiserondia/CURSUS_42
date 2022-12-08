/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:42:58 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/06 12:51:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	ax = a.GetX();
	Fixed	bx = b.GetX();
	Fixed	cx = c.GetX();
	Fixed	pointx = point.GetX();
	Fixed	ay = a.GetY();
	Fixed	by = b.GetY();
	Fixed	cy = c.GetY();
	Fixed	pointy = point.GetY();
	
	Fixed	vect1 = ax * (cy - ay) + (pointy - ay) * (cx - ax) - pointx * (cy - ay);
	vect1 = vect1 / ((by - ay) * (cx - ax) -  (bx - ax) * (cy - ay));
	Fixed	vect2 = pointy - ay - vect1 * (by - ay);
	vect2 = vect2 / (cy - ay);

	if (vect1 > 0 && vect2 > 0 && (vect1 + vect2) < 1)
		return true;
	return false;
}	