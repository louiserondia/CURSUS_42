/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/10 17:25:21 by lrondia          ###   ########.fr       */
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

// template <class T, class Allocator>
// void	debugVector(Vector<V3, Allouloucator<V3> > vector)
// {
// 	for (size_t i = 0; i < vector.size(); i++)
// 		vector[i].printV3();
// 	std::cout << "vector capacity : " << vector.capacity() << "\n";
// 	std::cout << "vector size : " << vector.size() << "\n";
// }

int	main(void)
{
	Allouloucator<std::string>		allocator;
	Vector<V3, Allouloucator<V3> >	vector;

	std::cout << "\n	| PUSH_BACK 3 VECTORS |\n\n";
	{
		vector.push_back(V3(6.6f, 6.6f, 6.6f));
		vector.push_back(V3());
		vector.push_back(V3(3, 4, 5));
		for (size_t i = 0; i < vector.size(); i++)
			vector[i].printV3();
		std::cout << "vector capacity : " << vector.capacity() << "\n";
		std::cout << "vector size : " << vector.size() << "\n\n";
	}

	std::cout << "	| POP_BACK, RESIZE (smaller) & RESERVE (6) |\n\n";
	{
		vector.pop_back();
		vector.resize(2, V3(9, 9, 9));
		vector.reserve(6);
		for (size_t i = 0; i < vector.size(); i++)
			vector[i].printV3();
		std::cout << "vector capacity : " << vector.capacity() << "\n";
		std::cout << "vector size : " << vector.size() << "\n\n";
	}

	std::cout << "	| CLEAR (size = 0), RESIZE (1) & PUSH_BACK |\n\n";
	{
		vector.clear();
		vector.resize(1, V3(9, 9, 9));
		vector.push_back(V3(3, 4, 5));
		vector.push_back(V3(8.8f, 8.8f, 8.8f));
		for (size_t i = 0; i < vector.size(); i++)
			vector[i].printV3();
		std::cout << "vector capacity : " << vector.capacity() << "\n";
		std::cout << "vector size : " << vector.size() << "\n\n";
	}

	std::cout << "	| FRONT, AT & BACK |\n\n";
	std::cout << "vector front : ";
	vector.front().printV3();
	std::cout << "vector at 1 : ";
	vector.at(1).printV3();
	std::cout << "vector back : ";
	vector.back().printV3();

	// std::cout << "vector[" << i << "] : " << vector[i] << "\n";
}