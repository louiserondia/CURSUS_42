/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/03 17:05:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TemplateFunctions.tpp"

/*
----> mon main <----

int	main(void)	{

	int		a = 2;
	int		b = 1;
	float	c = 3.3f;
	float	d = 1;
	char 	l = 'l';
	char 	x = 'x';

	std::cout << "\nSWAP A & B" << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;
	swap<int>(a, b);
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;

	std::cout << "\nSWAP C & D" << std::endl;
	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << std::endl;
	swap<float>(c, d);
	std::cout << "c : " << c << std::endl;
	std::cout << "d : " << d << std::endl;

	std::cout << "\nMIN and MAX A & B" << std::endl;
	std::cout << "a (1) or b (2) is smaller ?	" << min<int>(a, b) << std::endl;
	std::cout << "a (1) or b (2) is bigger ?	" << max<int>(a, b) << std::endl;

	std::cout << "\nMIN and MAX L & X" << std::endl;
	std::cout << "l or x is smaller ?	" << min<char>(l, x) << std::endl;
	std::cout << "l or x is bigger ?	" << max<char>(l, x) << std::endl;
	return 0;
}
*/

int	main(void) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}