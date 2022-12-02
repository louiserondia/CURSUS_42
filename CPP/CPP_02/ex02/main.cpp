/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:01:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/02 15:41:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(5.05f);
	Fixed d(4);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "---------- my tests -----------" << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a == c : " << (a == c) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "c > ++c : " << (c > ++c) << std::endl;
	c--;
	std::cout << " et c > c++ : " << (c > c++) << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "d - 1 = " << d - Fixed(1) << std::endl;
	std::cout << "d + 0.3f = " << d + Fixed(0.3f) << std::endl;
	std::cout << "d * 3 = " << d * Fixed(3) << std::endl;
	std::cout << "d / 1000 = " << d / Fixed(1000) << std::endl;

	return 0;
}
