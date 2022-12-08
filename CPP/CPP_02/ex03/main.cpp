/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/06 12:54:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
	Point a(2, 1);
	Point b(3, 3);
	Point c(1, 3);
	Point point1(1, 1);
	Point point2(2, 2);
	Point point3(0, 0);
	Point point4(1.8, 2);
	
	std::cout << "is point1 inside ABC triangle ? --> " << bsp(a, b, c, point1) << std::endl;
	std::cout << "is point2 inside ABC triangle ? --> " << bsp(a, b, c, point2) << std::endl;
	std::cout << "is point3 inside ABC triangle ? --> " << bsp(a, b, c, point3) << std::endl;
	std::cout << "is point4 inside ABC triangle ? --> " << bsp(a, b, c, point4) << std::endl;
	std::cout << "is c inside ABC triangle ? --> " << bsp(a, b, c, c) << std::endl;

	return 0;
}
