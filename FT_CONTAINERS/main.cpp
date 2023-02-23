/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/23 19:35:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Allouloucator.hpp"
#include "Vector.hpp"
#include "V3.hpp"
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

template < typename T>
void	print_vector(Vector<T> vector, std::string name) {
	std::cout << name << " : | ";
	for (Iterator<T> it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " | ";
	std::cout << std::endl << std::endl;
}

int	main(void)
{
	Allouloucator<std::string>		allocator;
	
	Vector<V3, Allouloucator<V3> >	vector;

	std::cout << "\n	| PUSH_BACK 3 VECTORS |\n\n";

		vector.push_back(V3(6.6f, 6.6f, 6.6f));
		vector.push_back(V3());
		vector.push_back(V3(3, 4, 5));
		for (size_t i = 0; i < vector.size(); i++)
			vector.at(i).printV3();
		std::cout << "vector capacity : " << vector.capacity() << "\n";
		std::cout << "vector size : " << vector.size() << "\n\n";


	std::cout << "	| RESIZE (bigger then smaller), POP_BACK & RESERVE (6) |\n\n";

		vector.resize(5, V3(9, 9, 9));
		for (size_t i = 0; i < vector.size(); i++)
			vector[i].printV3();
		vector.resize(4, V3(9, 9, 9));
		vector.pop_back();
		vector.reserve(6);
		std::cout << "--------------------" << std::endl;
		for (size_t i = 0; i < vector.size(); i++)
			vector[i].printV3();
		std::cout << "vector capacity : " << vector.capacity() << "\n";
		std::cout << "vector size : " << vector.size() << "\n\n";


	std::cout << "	| CLEAR (size = 0), RESIZE (1) & PUSH_BACK (2) |\n\n";

		vector.clear();
		vector.resize(1, V3(9, 9, 9));
		vector.push_back(V3(3, 4, 5));
		vector.push_back(V3(8.8f, 8.8f, 8.8f));
		for (size_t i = 0; i < vector.size(); i++)
			vector[i].printV3();
		std::cout << "vector capacity : " << vector.capacity() << "\n";
		std::cout << "vector size : " << vector.size() << "\n\n";


	std::cout << "	| FRONT, AT & BACK |\n\n";

		std::cout << "vector front : ";
		vector.front().printV3();
		std::cout << "vector at 1 : ";
		vector.at(1).printV3();
		std::cout << "vector back : ";
		vector.back().printV3();


	std::cout << "\n	| CONSTRUCTOR W/ SIZE & VALUE |\n\n";

		Vector<std::string, Allouloucator<std::string> >	str_tab(4, "lol");
		print_vector(str_tab, "str_tab");
		std::cout << "str_tab size : " << str_tab.size() << std::endl;


	std::cout << "\n	| CONSTRUCTOR W/ ITERATORS |\n\n";

		int tab[4] = {0, 1, 2, 3 };
		Vector<int, Allouloucator<int> >	it_tab(tab, tab + 4);
		print_vector(it_tab, "tab");


	std::cout << "\n	| ITERATORS |\n\n";

		Vector<int, Allouloucator<int> >	int_tab;

		int_tab.push_back(10);
		int_tab.push_back(40);
		int_tab.push_back(6);
		int_tab.push_back(8);
		int_tab.push_back(1000000);
		print_vector(int_tab, "int_tab");
		std::cout << "int_tab[" << 1 << "] : " << int_tab[1] << "\n";


	std::cout << "\n	| ERASE 1st THEN 3rd ELEM |\n\n";
		std::cout << "return : " << *(int_tab.erase(int_tab.begin(), int_tab.begin() + 1)) << std::endl;
		int_tab.erase(int_tab.end() - 1);
		for (Iterator<int> it = int_tab.begin(); it != int_tab.end(); it++)
			print_vector(int_tab, "int_tab");


	std::cout << "\n	| SWAP INT_TAB AND LOL |\n\n";

		Vector<int>	lol;
		Vector<int>	oui;
		oui.push_back(1);
		lol.push_back(666);
		lol.push_back(777);
		lol.push_back(888);
		lol.push_back(999);
		lol.swap(oui);
		print_vector(lol, "lol");
		print_vector(oui, "oui");


	std::cout << "\n	| INSERT n TIMES A VALUE INSIDE VECTOR |\n\n";
	
		Vector<int> new_tab(it_tab);

		print_vector(new_tab, "new_tab before insert");
		new_tab.insert(new_tab.begin() + 1, 4, 9);
		print_vector(new_tab, "new_tab after insert");


	std::cout << "\n	| INSERT WITH ITERATORS |\n\n";

		new_tab.insert(new_tab.end() - 6, oui.begin(), oui.end());
		print_vector(new_tab, "new_tab after insert w/ iterators");

}
