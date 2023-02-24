/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   V3.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:43:00 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/24 14:07:11 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector.hpp"

struct V3	{
	float x;
	float y;
	float z;

	V3() : x(0), y(0), z(0) {}
	V3(float x, float y, float z) : x(x), y(y), z(z) {}
	V3(const V3 &copy) : x(copy.x), y(copy.y), z(copy.z) {}
	~V3() {}

	void	printV3(){
		std::cout << "x " << x << "	y " << y << "	z " << z << "\n";
	}
};

template <class T, class Allocator>
void	debugVector(ft::vector<V3> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		vector[i].printV3();
	std::cout << "vector capacity : " << vector.capacity() << "\n";
	std::cout << "vector size : " << vector.size() << "\n";
}
