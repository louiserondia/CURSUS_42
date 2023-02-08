/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/08 18:51:11 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Allouloucator.hpp"
#include "Vector.hpp"
#include "Iterator.hpp"
#include <memory>
#include <vector>

class A
{
	private:
	public:
		A() { std::cout << "Constructor\n"; }
		A(const A &) { std::cout << "Copy constructor\n"; }
		~A() { std::cout << "Destructor\n"; }
};


int	main(void)
{
	Allouloucator<std::string>	allocator;
	std::string					*str;

	str = allocator.allocate(1);
	std::cout << "_n_alloc :" << allocator.get_n_alloc() << "\n";
	allocator.construct(str, "hello");
	std::cout << *str << "\n";

	std::vector<int>	values = {1, 2, 3, 4, 5};
	
	for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)	{
		std::cout << "Value of iterator" << *it << "\n";
	}
	
}