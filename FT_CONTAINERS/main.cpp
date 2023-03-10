/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/10 17:54:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "bst.hpp"
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
		lol.push_back(555);
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

		new_tab.insert(new_tab.end() - 4, oui.begin(), oui.end());
		print_vector(new_tab, "new_tab after insert w/ iterators");
		

	std::cout << "\n	| STACK |\n\n";
		
		stack<int>	stacos;

		for (int i = 0; i < 10 ; i += 2) {
			stacos.push(i);
			std::cout << "stacos : " << stacos.top() << std::endl;	
		}
		for (int i = 0; i < 10 ; i += 2) {
			std::cout << "stacos : " << stacos.top() << std::endl;
			stacos.pop();
		}


	std::cout << "\n	| PAIR |\n\n";
	
		pair<int, std::string>	pair1(1, "lol");
		pair<std::string, vector<int> >	pair2("test", new_tab);
		
		std::cout << "1. pair first :		" << pair1.first << std::endl;
		std::cout << "1. pair second :	" << pair1.second << std::endl << std::endl;

		std::cout << "2. pair first :	 " << pair2.first << std::endl;
		std::cout << "2. pair second";
		print_vector(pair2.second, "");
		std::cout << std::endl;


	std::cout << "\n	| MAKE PAIR |\n\n";
	
		std::cout << ft::make_pair(2, std::string("yes"));

	
	std::cout << "\n	| BINARY SEARCH TREE w/ int |\n\n";

		Tree<int, int>		tree;
		ft::pair<int, int>	lol0(0, 0);
		ft::pair<int, int>	lol1(1, 2);
		ft::pair<int, int>	lol2(2, 2);

		tree.Insert(lol0);
		tree.Insert(lol1);
		tree.Insert(lol2);
		std::cout << "search lol0 : "  << tree.Search(2) << std::endl;

	
	std::cout << "\n	| BINARY SEARCH TREE w/ std::string |\n\n";

		Tree<std::string, std::string>	tree_str;
		ft::pair<std::string, std::string>	lol3("a", "oui");
		ft::pair<std::string, std::string>	lol4("b", "lol");
		ft::pair<std::string, std::string>	lol5("c", "prout");

		tree_str.Insert(lol3);
		tree_str.Insert(lol4);
		std::cout << "search lol5 : " << tree_str.Search("a") << std::endl;

	
	std::cout << "\n	| TESTING REMOVE ON RBT |\n\n";
	
		Tree<int, int>		rbt;
		rbt.Insert(lol2);
		std::cout << "search before removing 0	: " << rbt.Search(2) << std::endl;
		rbt.remove(rbt.first());
		std::cout << "search after removing 0	:	" << rbt.Search(2) << std::endl;


}
