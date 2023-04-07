/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/07 18:54:29 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "Rbt.hpp"
#include "set.hpp"
#include "map.hpp"
#include "set.hpp"
#include "V3.hpp"

using namespace ft;

// ^--------------------------------------------------------^
// ^			 __  __    ___     ___    _  _   			^
// ^			|  \/  |  /   \   |_ _|  | \| |  			^
// ^			| |\/| |  | - |    | |   | .` |  			^
// ^			|_|__|_|  |_|_|   |___|  |_|\_|  			^
// ^			_|"""""|_|"""""|_|"""""|_|"""""| 			^
// ^			"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 			^
// ^--------------------------------------------------------^

// ^----------------------------------------------------^
// ^													^
// ^			 PRINT VECTOR AND STUFF		 		 	^
// ^													^
// ^----------------------------------------------------^

template < typename T>
void	print_vector(vector<T> v, std::string name) {
	std::cout << name << " : | ";
	for (typename vector<T>::iterator it = v.begin(); it != v.end(); it ++)
		std::cout << *it << " | ";
	std::cout << std::endl << std::endl;
}

void print_v(Rbt<std::string, std::string> v) {
	std::cout << "\n	------- Print v -------\n";
	for (Rbt<std::string, std::string>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it;
	std::cout << "	v size : " << v.size() << std::endl;
	std::cout << "	-----------------------\n\n";
}

class A
{
	private:
	public:
		A() { std::cout << "Constructor\n"; }
		A(const A &) { std::cout << "Copy constructor\n"; }
		~A() { std::cout << "Destructor\n"; }
};

// ^----------------------------------------------------^
// ^													^
// ^						MAIN			 		 	^
// ^													^
// ^----------------------------------------------------^

int	main(void) {
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
		for (vector<int>::reverse_iterator jt = int_tab.rbegin(); jt != int_tab.rend(); jt++)
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


	std::cout << "\n	| insert n TIMES A VALUE INSIDE VECTOR |\n\n";
	
		vector<int> new_tab(it_tab);

		print_vector(new_tab, "new_tab before insert");
		new_tab.insert(new_tab.begin() + 1, 4, 9);
		print_vector(new_tab, "new_tab after insert");


	std::cout << "\n	| insert WITH ITERATORS |\n\n";

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
		
		std::cout << "1. key :	" << pair1.first << std::endl;
		std::cout << "1. value :	" << pair1.second << std::endl << std::endl;

		std::cout << "2. key :	" << pair2.first << std::endl;
		std::cout << "2. value";
		print_vector(pair2.second, "");
		std::cout << std::endl;


	std::cout << "\n	| MAKE PAIR |\n\n";
	
		std::cout << ft::make_pair(2, std::string("yes"));

	
	std::cout << "\n	| RED BLACK TREE w/ std::string |\n\n";

		Rbt<std::string, std::string>	tree_str;
		ft::pair<std::string, std::string>	str3("a", "oui");
		ft::pair<std::string, std::string>	str4("b", "str");
		ft::pair<std::string, std::string>	str5("c", "prout");

		tree_str.insert(str3);
		tree_str.insert(str4);
		std::cout << "finding something existing (a) : " << *tree_str.find("a");
		std::cout << "finding something else (y) : " << *tree_str.find("y") << std::endl;

	
	std::cout << "\n	| RED BLACK TREE w/ int |\n\n";

		Rbt<int, int>		tree;
		ft::pair<int, int>	lol0(-1, 0);
		ft::pair<int, int>	lol1(1, 0);
		ft::pair<int, int>	lol2(2, 0);

		std::cout << "height empty : 0" << std::endl;
		tree.insert(lol0);
		std::cout << "iterator begin() : " << *tree.begin();
 		tree.insert(lol1);
		tree.insert(lol2);
		std::cout << "\nAdded (40, 0), (1, 0) and (2, 0)\n";
		std::cout << "finding key '2' : "  << *tree.find(2);
		std::cout << "finding key '7' : "  << *tree.find(7);

	std::cout << "\n	| TESTING RED BLACK TREE (int) insert WITH ITS HEIGHT |\n\n";

		ft::pair<int, int>	lol3(3, 0);
		ft::pair<int, int>	lol4(4, 0);
		ft::pair<int, int>	lol5(5, 0);
		ft::pair<int, int>	lol6(6, 0);
		ft::pair<int, int>	lol7(7, 0);
		ft::pair<int, int>	lol8(8, 0);
		ft::pair<int, int>	lol9(9, 0);
		ft::pair<int, int>	lol10(10, 0);

		// std::cout << "Previous height with 3 elements in the tree : " << tree.height() << std::endl << std::endl;
		tree.insert(lol3);
		tree.insert(lol4);
		std::cout << "Added 3, 4.\n";
		tree.insert(lol5);
		tree.insert(lol6);
		tree.insert(lol7);
		tree.insert(lol8);
		std::cout << "Added 5, 6, 7, 8.\n";
		tree.insert(lol9);
		tree.insert(lol10);
		std::cout << "Added 9 and 10.\n";
	
	
	std::cout << "\n	| ITERATORS OF RED BLACK TREE |\n\n";

		std::cout << "iterator begin() : " << *tree.begin();
		std::cout << "iterator ++begin() : " << *(++tree.begin());
		std::cout << "iterator end() : " << *tree.end();
		std::cout << "iterator --end() : " << *(--tree.end());

		std::cout << "\n-----------------------------------------\n " << std::endl;

		for (Rbt<int, int>::const_iterator it = tree.begin(); it != tree.end(); ++it)
			std::cout << "iterator : "<< *it;
		std::cout << "\niterator begin() (to check that begin didn't change) : " << *tree.begin() << std::endl;

		Rbt<std::string, std::string> v;
		for (int i = 0 ; i < 26; i++)	
			v.insert(Rbt<std::string, std::string>::value_type(std::string(1,(char)('a' + i)), "yooo"));

	std::cout << "\n	| ERASE W/ RED BLACK TREE |\n\n";

		std::cout << "\n1. erasing first element of v (a, yooo) -> ";
		v.erase(std::string(1,(char)('a')));
		print_v(v);

		std::cout << "\n2. erasing all elements except begin and end -> ";
		v.erase(++v.begin(), --v.end());
		print_v(v);
	
		std::cout << "3. erasing the rest ";
		v.erase(v.begin(), v.end());
		print_v(v);

	std::cout << "\n	| TEST INSERT 1000 ELEMENTS TO MAP |\n\n";

	map<int, int>	map1;

	for (int i = 0; i < 1000; i++)
		map1.insert(ft::make_pair(i, i * i));

	std::cout << "first element of map1 : " << *map1.begin();

	std::cout << "\n	| TEST INSERT 100 ELEMENTS TO SET |\n\n";

	set<int>	set1;

	for (int i = 0; i < 100000; i++)
		set1.insert(i);

	std::cout << "last element of set1 : " << *--set1.end() << std::endl;
	
	// system("leaks ft_containers");
}
