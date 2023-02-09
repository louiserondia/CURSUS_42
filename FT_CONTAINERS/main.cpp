/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/09 18:51:31 by lrondia          ###   ########.fr       */
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

struct V3	{
	float x;
	float y;
	float z;

	V3() : x(0), y(0), z(0) { std::cout << "Default constructor\n"; }
	V3(float x, float y, float z) : x(x), y(y), z(z) { std::cout << "Constructor\n"; }
	V3(const V3 &copy) : x(copy.x), y(copy.y), z(copy.z) { std::cout << "Copy constructor\n"; }
	~V3() { std::cout << "Destroy\n"; }

	void	printV3(){
		std::cout << "x : " << x << ", y : " << y << ", z : " << z << "\n";
	}
};

int	main(void)
{
	Allouloucator<std::string>		allocator;
	Vector<V3, Allouloucator<V3> >	vector;
	// std::string						*str;

	// str = allocator.allocate(1);
	// std::cout << "_n_alloc :" << allocator.get_n_alloc() << "\n";
	// allocator.construct(str, "hello");
	// std::cout << *str << "\n";

	vector.push_back(V3());
	vector.push_back(V3(0, 1, 2));
	// vector.push_back(V3(3, 4, 5)); // --------> crash quand on essaie de changer la taille, utiliser le destructeur manuellement ?
	// vector.push_back(V3(10, 11, 12));
	// vector.push_back(V3(13, 14, 15));

	std::cout << "vector capacity : " << vector.capacity() << "\n";
	std::cout << "vector size : " << vector.size() << "\n";

	for (size_t i = 0; i < vector.size(); i++)
		vector[i].printV3();
	// std::cout << "vector[" << i << "] : " << vector[i] << "\n";
		
	
}