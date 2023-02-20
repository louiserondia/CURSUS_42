/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/20 15:44:10 by lrondia          ###   ########.fr       */
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
			vector.at(i).printV3();
		std::cout << "vector capacity : " << vector.capacity() << "\n";
		std::cout << "vector size : " << vector.size() << "\n\n";
	}

	std::cout << "	| POP_BACK, RESIZE (smaller) & RESERVE (6) |\n\n";
	{
		vector.pop_back();
		vector.resize(5, V3(9, 9, 9));
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


	std::cout << "\n	| CONSTRUCTOR W/ SIZE & VALUE |\n\n";
	Vector<std::string, Allouloucator<std::string> >	str_tab(4, "lol");
	for (Iterator<std::string> it = str_tab.begin(); it != str_tab.end(); it++)
		std::cout << "str_tab : " << *it << std::endl;	
	std::cout << "str_tab size : " << str_tab.size() << std::endl;

	std::cout << "\n	| CONSTRUCTOR W/ ITERATORS |\n\n";
	int tab[4] = {0, 1, 2, 3 };
	Vector<int, Allouloucator<int> >	it_tab(tab, tab + 4);

	for (Iterator<int> it = it_tab.begin(); it != it_tab.end(); it++)
		std::cout << "tab : "<< *it << std::endl;

	Vector<int, Allouloucator<int> >	int_tab;

	int_tab.push_back(10);
	int_tab.push_back(40);
	int_tab.push_back(6);
	int_tab.push_back(8);
	int_tab.push_back(1000000);
	std::cout << "\n	| ITERATORS |\n\n";
	for (Iterator<int> it = int_tab.begin(); it != int_tab.end(); it++)
		std::cout << "int_tab : "<< *it << std::endl;

	std::cout << "int_tab[" << 1 << "] : " << int_tab[1] << "\n";

	std::cout << "\n	| ERASE 1st THEN 3rd ELEM |\n\n";
	std::cout << "return :" << *(int_tab.erase(int_tab.begin(), int_tab.begin() + 1)) << std::endl;
	int_tab.erase(int_tab.end() - 1);
	for (Iterator<int> it = int_tab.begin(); it != int_tab.end(); it++)
		std::cout << "iterator : "<< *it << std::endl;

	std::vector<int>	lol;
	lol.push_back(10);
	lol.push_back(40);
	lol.push_back(6);
	lol.push_back(8);
	lol.push_back(1000000);
	std::cout << "actual return :" << *(lol.erase(lol.begin(), lol.begin() + 1)) << std::endl;
	lol.erase(lol.end() - 1);
	for (std::vector<int>::iterator it = lol.begin(); it != lol.end(); it++)
		std::cout << "actual vector : "<< *it << std::endl;

	// std::cout << "\n	| INSERT INSIDE VECTOR |\n\n";
	// int i = 1;
	// int_tab.insert(&i, 1);
	// int_tab.insert(int_tab.begin(), 1);

	Iterator<int> it = int_tab.begin();
	it - 1;
}