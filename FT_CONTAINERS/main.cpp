/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/27 15:26:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "V3.hpp"
#include <list>

using namespace ft;

class A
{
	private:
	public:
		A() { std::cout << "Constructor\n"; }
		A(const A &) { std::cout << "Copy constructor\n"; }
		~A() { std::cout << "Destructor\n"; }
};

template < typename T>
void	print_vector(vector<T> vector, std::string name) {
	std::cout << name << " : | ";
	for (Iterator<T> it = vector.begin(); it != vector.end(); it ++)
		std::cout << *it << " | ";
	std::cout << std::endl << std::endl;
}

int	main(void)
{
	Allouloucator<std::string>		allocator;
	
	vector<V3, Allouloucator<V3> >	vect;

	std::cout << "\n	| PUSH_BACK 3 VECTORS |\n\n";

		vect.push_back(V3(6.6f, 6.6f, 6.6f));
		vect.push_back(V3());
		vect.push_back(V3(3, 4, 5));
		for (size_t i = 0; i < vect.size(); i++)
			vect.at(i).printV3();
		std::cout << "vector capacity : " << vect.capacity() << "\n";
		std::cout << "vector size : " << vect.size() << "\n\n";


	std::cout << "	| RESIZE (bigger then smaller), POP_BACK & RESERVE (6) |\n\n";

		vect.resize(5, V3(9, 9, 9));
		for (size_t i = 0; i < vect.size(); i++)
			vect[i].printV3();
		vect.resize(4, V3(9, 9, 9));
		vect.pop_back();
		vect.reserve(6);
		std::cout << "--------------------" << std::endl;
		for (size_t i = 0; i < vect.size(); i++)
			vect[i].printV3();
		std::cout << "vector capacity : " << vect.capacity() << "\n";
		std::cout << "vector size : " << vect.size() << "\n\n";


	std::cout << "	| CLEAR (size = 0), RESIZE (1) & PUSH_BACK (2) |\n\n";

		vect.clear();
		vect.resize(1, V3(9, 9, 9));
		vect.push_back(V3(3, 4, 5));
		vect.push_back(V3(8.8f, 8.8f, 8.8f));
		for (size_t i = 0; i < vect.size(); i++)
			vect[i].printV3();
		std::cout << "vector capacity : " << vect.capacity() << "\n";
		std::cout << "vector size : " << vect.size() << "\n\n";


	std::cout << "	| FRONT, AT & BACK |\n\n";

		std::cout << "vector front : ";
		vect.front().printV3();
		std::cout << "vector at 1 : ";
		vect.at(1).printV3();
		std::cout << "vector back : ";
		vect.back().printV3();


	std::cout << "\n	| CONSTRUCTOR W/ SIZE & VALUE |\n\n";

		vector<std::string>	str_tab(4, "lol");
		print_vector(str_tab, "str_tab");
		std::cout << "str_tab size : " << str_tab.size() << std::endl;


	std::cout << "\n	| CONSTRUCTOR W/ ITERATORS |\n\n";

		int tab[4] = {0, 1, 2, 3 };
		vector<int, Allouloucator<int> >	it_tab(tab, tab + 4);
		print_vector(it_tab, "tab");


	std::cout << "\n	| ITERATORS |\n\n";

		vector<int, Allouloucator<int> >	int_tab;

		int_tab.push_back(10);
		int_tab.push_back(40);
		int_tab.push_back(6);
		int_tab.push_back(8);
		int_tab.push_back(1000000);
		print_vector(int_tab, "int_tab iterator");
		std::cout << "int_tab[" << 1 << "] : " << int_tab[1] << "\n";


	std::cout << "\n	| REVERSE ITERATORS |\n\n";
		
		std::cout << " int_tab reverse iterator : | ";
		for (ft::reverse_iterator<Iterator<int> > jt = int_tab.rbegin(); jt != int_tab.rend(); jt++)
		std::cout << *jt << " | ";
		std::cout << std::endl << std::endl;


	std::cout << "\n	| ERASE 1st THEN 3rd ELEM |\n\n";
		std::cout << "return : " << *(int_tab.erase(int_tab.begin(), int_tab.begin() + 1)) << std::endl;
		int_tab.erase(int_tab.end() - 1);
		print_vector(int_tab, "int_tab");


	std::cout << "\n	| SWAP INT_TAB AND LOL |\n\n";

		vector<int>	lol;
		vector<int>	oui;
		oui.push_back(1);
		lol.push_back(666);
		lol.push_back(777);
		lol.push_back(888);
		lol.push_back(999);
		lol.swap(oui);
		print_vector(lol, "lol");
		print_vector(oui, "oui");


	std::cout << "\n	| INSERT n TIMES A VALUE INSIDE VECTOR |\n\n";
	
		vector<int> new_tab(it_tab);

		print_vector(new_tab, "new_tab before insert");
		new_tab.insert(new_tab.begin() + 1, 4, 9);
		print_vector(new_tab, "new_tab after insert");


	std::cout << "\n	| INSERT WITH ITERATORS |\n\n";

		new_tab.insert(new_tab.end(), oui.begin(), oui.end());
		print_vector(new_tab, "new_tab after insert w/ iterators");

	std::cout << "\n	| INSERT WITH ITERATORS |\n\n";
	
		// std::list<int> lst;
		// std::list<int>::iterator lst_it;
	
		// lst_it = lst.begin();
		// for (int i = 1; lst_it != lst.end(); ++i)
		// 	*lst_it++ = i * 5;
		// vct.assign(lst.begin(), lst.end());
		//? pas d'operateur + avec la liste, doit etre géré ?
		

		vector<std::string> vct(10);

		for (unsigned long int i = 0; i < vct.size(); i++)
			vct[i] = std::string((vct.size() - i), i + 65);
		print_vector(vct, "vct");
		std::cout << "begin : " << *vct.begin() << std::endl;
		std::cout << "begin + 2 : " << *(vct.begin() + 2) << std::endl;
		std::cout << "begin + 3 : " << *(vct.begin() + 3) << std::endl;
}
