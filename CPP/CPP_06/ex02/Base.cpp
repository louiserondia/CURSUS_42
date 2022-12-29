/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:25:10 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/29 16:50:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void)	{
}

Base	*generate(void)	{
	srand(time(NULL));
	int	rand = std::rand() % 3;

	if (rand == 0)
		return new A;
	else if (rand == 1)
		return new B;
	else
		return new C;
}

void	identify(Base *p)	{
	if (dynamic_cast<A *>(p))
		std::cout << "The base is actually an A.\n";
	if (dynamic_cast<B *>(p))
		std::cout << "The base is actually a B.\n";
	if (dynamic_cast<C *>(p))
		std::cout << "The base is actually a C.\n";
}

void	identify(Base &p)	{
	A	a;
	B	b;
	C	c;

	try {
		a = dynamic_cast<A &>(p);
		std::cout << "The base is actually an A.\n";
	}
	catch (std::bad_cast &bc)	{
		try {
			b = dynamic_cast<B &>(p);
			std::cout << "The base is actually a B.\n";
		}
		catch (std::bad_cast &bc)	{
			try {
				c = dynamic_cast<C &>(p);
				std::cout << "The base is actually a C.\n";
			}
			catch (std::bad_cast &bc)	{}
		}
	}
}

