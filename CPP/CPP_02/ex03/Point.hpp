/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:51:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/02 19:07:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &src);
	~Point(void);

	const Fixed	GetX(void) const;
	const Fixed	GetY(void) const;
	Point		&operator=(const Point &rhs);
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif