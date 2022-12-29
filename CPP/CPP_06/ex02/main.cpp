/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:46 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/29 16:52:30 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int	main(void)	{

	std::cout << "identify type A" << std::endl;
	Base *a = new A();
	identify(a);
	identify(*a);
	delete a;

	std::cout << "identify type B" << std::endl;
	Base *b = new B();
	identify(b);
	identify(*b);
	delete b;

	std::cout << "identify type C" << std::endl;
	Base *c = new C();
	identify(c);
	identify(*c);
	delete c;

	std::cout << "identify type Random" << std::endl;
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;
	
	return 0;
}
