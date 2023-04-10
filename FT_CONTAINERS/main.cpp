/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:22:29 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/10 17:01:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "Rbt.hpp"
#include "set.hpp"
#include "map.hpp"
#include "set.hpp"

#include <vector>
#include <stack>
#include <set>
#include <map>
#include <set>

#define NS ft
#define STREAM std::cout


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
// ^				  PRINT PAIR			 		 	^
// ^													^
// ^----------------------------------------------------^

	template <class T1, class T2>
	std::ostream	&operator<<(std::ostream &o, const NS::pair<T1, T2> &rhs)	{
		o << "	key : " << rhs.first;
		o << " | value : " << rhs.second << std::endl;
		return o;
	}


// ^----------------------------------------------------^
// ^													^
// ^				   STRUCT VECTOR 3		 		 	^
// ^													^
// ^----------------------------------------------------^

struct V3	{
	float x;
	float y;
	float z;

	V3() : x(0), y(0), z(0) {}
	V3(float x, float y, float z) : x(x), y(y), z(z) {}
	V3(const V3 &copy) : x(copy.x), y(copy.y), z(copy.z) {}
	~V3() {}

	void	printV3(){
		STREAM << "x " << x << "	y " << y << "	z " << z << "\n";
	}
};

void	debugVector(NS::vector<V3> &vect) {
	for (size_t i = 0; i < vect.size(); i++)
		vect[i].printV3();
	if (vect.empty())
		STREAM << "vector is empty.\n";
	STREAM << "capacity : " << vect.capacity() << ", size : " << vect.size() << "\n";
	STREAM << "----------------------\n";
}

// ^----------------------------------------------------^
// ^													^
// ^			 PRINT VECTOR AND STUFF		 		 	^
// ^													^
// ^----------------------------------------------------^

template < typename T>
void	print_vector(NS::vector<T> &v, std::string name) {
	STREAM << name << " : | ";
	for (typename NS::vector<T>::iterator it = v.begin(); it != v.end(); it ++)
		STREAM << *it << " | ";
	STREAM << std::endl << std::endl;
}

void print_v(NS::map<std::string, std::string> &v) {
	STREAM << "\n	------- Print v -------\n";
	for (NS::map<std::string, std::string>::iterator it = v.begin(); it != v.end(); ++it)
		STREAM << *it;
	STREAM << "	v size : " << v.size() << std::endl;
	STREAM << "	-----------------------\n\n";
}

class A {
	private:
	public:
		A() { STREAM << "Constructor\n"; }
		A(const A &) { STREAM << "Copy constructor\n"; }
		~A() { STREAM << "Destructor\n"; }
};

// ^----------------------------------------------------^
// ^													^
// ^						MAIN			 		 	^
// ^													^
// ^----------------------------------------------------^

int	main(void) {
	ft::Allouloucator<std::string>		allocator;

	STREAM << "	|----------------------|\n";
	STREAM << "	|                      |\n";
	STREAM << "	|        VECTOR        |\n";
	STREAM << "	|                      |\n";
	STREAM << "	|----------------------|\n";
	STREAM << "\n	| CONSTRUCT VECTOR W/ NOTHING, OTHER VECTOR, SIZE & VALUE AND ITERATORS |\n\n";
	
	NS::vector<V3>	vect;
	NS::vector<V3>	vect2(3, V3(1, 2, 3));
	NS::vector<V3>	vect3(vect2);
	NS::vector<V3>	vect4(vect2.begin(), vect2.end());
	debugVector(vect);
	debugVector(vect2);
	debugVector(vect3);
	debugVector(vect4);

	STREAM << "\n	| PUSH_BACK 3 VECTORS |\n\n";

		vect.push_back(V3(6.6f, 6.6f, 6.6f));
		vect.push_back(V3());
		vect.push_back(V3(3, 4, 5));
		debugVector(vect);

	STREAM << "\n	| RESIZE (bigger then smaller), POP_BACK & RESERVE (6) |\n\n";

		vect.resize(5, V3(9, 9, 9));
		STREAM << "\nafter resize bigger :\n";
		debugVector(vect);
		vect.resize(4, V3(9, 9, 9));
		STREAM << "\nafter resize smaller :\n";
		debugVector(vect);
		vect.pop_back();
		STREAM << "\nafter pop_back :\n";
		debugVector(vect);
		vect.reserve(7);
		STREAM << "\nafter reserve :\n";
		debugVector(vect);

	STREAM << "	| CLEAR (size = 0), RESIZE (1) & PUSH_BACK (2) |\n\n";

		vect.clear();
		vect.resize(1, V3(9, 9, 9));
		vect.push_back(V3(3, 4, 5));
		vect.push_back(V3(8.8f, 8.8f, 8.8f));
		debugVector(vect);


	STREAM << "	| OPERATOR[], FRONT, AT & BACK |\n\n";

		vect[0] = V3(0, 0, 0);
		STREAM << "vector[0] :   ";
		vect[0].printV3();
		STREAM << "vector front : ";
		vect.front().printV3();
		STREAM << "vector at 1 : ";
		vect.at(1).printV3();
		STREAM << "vector back : ";
		vect.back().printV3();


	STREAM << "\n	| CONSTRUCTOR W/ SIZE & VALUE |\n\n";

		NS::vector<std::string>	str_tab(4, "lol");
		print_vector(str_tab, "str_tab");
		STREAM << "str_tab size : " << str_tab.size() << std::endl;


	STREAM << "\n	| CONSTRUCTOR W/ ITERATORS |\n\n";

		int tab[4] = {0, 1, 2, 3 };
		NS::vector<int>	it_tab(tab, tab + 4);
		print_vector(it_tab, "tab");


	STREAM << "\n	| ITERATORS |\n\n";

		NS::vector<int>	int_tab;

		int_tab.push_back(10);
		int_tab.push_back(40);
		int_tab.push_back(6);
		int_tab.push_back(8);
		int_tab.push_back(1000000);
		print_vector(int_tab, "int_tab iterator");
		STREAM << "int_tab[" << 1 << "] : " << int_tab[1] << "\n";


	STREAM << "\n	| REVERSE ITERATORS |\n\n";
		
		STREAM << " int_tab reverse iterator : | ";
		for (NS::vector<int>::reverse_iterator jt = int_tab.rbegin(); jt != int_tab.rend(); jt++)
		STREAM << *jt << " | ";
		STREAM << std::endl << std::endl;


	STREAM << "\n	| ERASE 1st THEN 3rd ELEM |\n\n";
		STREAM << "return : " << *(int_tab.erase(int_tab.begin(), int_tab.begin() + 1)) << std::endl;
		int_tab.erase(int_tab.end() - 1);
		print_vector(int_tab, "int_tab");


	STREAM << "\n	| SWAP INT_TAB AND LOL |\n\n";

		NS::vector<int>	lol;
		NS::vector<int>	oui;
		oui.push_back(1);
		lol.push_back(555);
		lol.push_back(666);
		lol.push_back(777);
		lol.push_back(888);
		lol.push_back(999);
		lol.swap(oui);
		print_vector(lol, "lol");
		print_vector(oui, "oui");


	STREAM << "\n	| insert n TIMES A VALUE INSIDE VECTOR |\n\n";
	
		NS::vector<int> new_tab(it_tab);

		print_vector(new_tab, "new_tab before insert");
		new_tab.insert(new_tab.begin() + 1, 4, 9);
		print_vector(new_tab, "new_tab after insert");


	STREAM << "\n	| insert WITH ITERATORS |\n\n";

		new_tab.insert(new_tab.end() - 4, oui.begin(), oui.end());
		print_vector(new_tab, "new_tab after insert w/ iterators");
	
	
	STREAM << "\n	| OPERATOR = |\n\n";
	
	NS::vector<int> copy = oui;
	print_vector(oui, "oui");
	print_vector(copy, "copy (is a copy of oui)");
	
	
	STREAM << "\n	| ASSIGN |\n\n";

	STREAM << "clearing oui and assigning it all copy elements except begin and end\n";
	oui.clear();
	oui.assign(++copy.begin(), --copy.end());
	print_vector(oui, "oui");
	
	
	STREAM << "\n	| COMPARISON OPERATORS |\n\n";

	STREAM << "is oui == lol ? " << (oui == lol) << std::endl;
	STREAM << "is oui == oui ? " << (oui == oui) << std::endl;
	STREAM << "is oui < lol ? " << (oui < lol )<< std::endl;
	STREAM << "is oui >= lol ? " << (oui >= lol) << std::endl << std::endl;
	
	
	STREAM << "	|----------------------|\n";
	STREAM << "	|                      |\n";
	STREAM << "	|        STACK         |\n";
	STREAM << "	|                      |\n";
	STREAM << "	|----------------------|\n";
		
		NS::stack<int>	stacos;

		STREAM << "\npushing 5 elements on top of stacos\n";
		for (int i = 0; i < 10 ; i += 2) {
			stacos.push(i);
			STREAM << "stacos : " << stacos.top() << std::endl;	
		}
		STREAM << "\npoping those 5 elements\n";
		for (int i = 0; i < 10 ; i += 2) {
			STREAM << "ciao " << stacos.top() << std::endl;
			stacos.pop();
		}
		STREAM << "stacos is now : ";
		if (stacos.empty()) { STREAM << "empty\n\n"; }

	STREAM << "	|----------------------|\n";
	STREAM << "	|                      |\n";
	STREAM << "	|         PAIR         |\n";
	STREAM << "	|                      |\n";
	STREAM << "	|----------------------|\n";		

		NS::pair<int, std::string>	pair1(1, "lol");
		NS::pair<std::string, NS::vector<int> >	pair2("test", new_tab);
		
		STREAM << "1. key :	" << pair1.first << std::endl;
		STREAM << "1. value :	" << pair1.second << std::endl << std::endl;

		STREAM << "2. key :	" << pair2.first << std::endl;
		STREAM << "2. value";
		print_vector(pair2.second, "");
		STREAM << std::endl;

	STREAM << "\n	| MAKE PAIR |\n\n";
	
		STREAM << NS::make_pair(2, std::string("yes"));

	STREAM << "	|----------------------|\n";
	STREAM << "	|                      |\n";
	STREAM << "	|          MAP         |\n";
	STREAM << "	|                      |\n";
	STREAM << "	|----------------------|\n";		
	
	STREAM << "\n	| MAP w/ std::string |\n\n";

		NS::map<std::string, std::string>	tree_str;
		NS::pair<std::string, std::string>	str3("a", "oui");
		NS::pair<std::string, std::string>	str4("b", "str");
		NS::pair<std::string, std::string>	str5("c", "prout");

	STREAM << "\n	| INSERT 2 elem, FIND AND COUNT |\n\n";
		
		tree_str.insert(str3);
		tree_str.insert(str4);
		STREAM << "finding something existing (a) : " << *tree_str.find("a");
		STREAM << "finding something else (y) : " << *tree_str.find("y") << std::endl;
		STREAM << "counting a : " << tree_str.count("a") << std::endl;
		STREAM << "counting y : " << tree_str.count("y") << std::endl;

	
	STREAM << "\n	| RED BLACK TREE w/ int |\n\n";

		NS::map<int, int>		tree;
		NS::pair<int, int>	lol0(-1, 0);
		NS::pair<int, int>	lol1(1, 0);
		NS::pair<int, int>	lol2(2, 0);

		STREAM << "height empty : 0" << std::endl;
		tree.insert(lol0);
		STREAM << "iterator begin() : " << *tree.begin();
 		tree.insert(lol1);
		tree.insert(lol2);
		STREAM << "\nAdded (40, 0), (1, 0) and (2, 0)\n";
		STREAM << "finding key '2' : "  << *tree.find(2);
		STREAM << "finding key '7' : "  << *tree.find(7);

	STREAM << "\n	| INSERT + construct map empty  |\n\n";

		NS::map<int, int>	map_tmp;
		for (int i = 0; i < 10; i++)
			map_tmp.insert(NS::make_pair(i, 0));
		
		STREAM << "Inserting first 10 elemts in map_tmp : \n";
		for (NS::map<int, int>::iterator it = map_tmp.begin(); it != map_tmp.end(); it++)
			STREAM << *it;
			
		STREAM << "\nNow insert all those elements in mappy with iterators :\n";
		NS::map<int, int>	mappy(map_tmp.begin(), map_tmp.end());
		for (NS::map<int, int>::iterator it = map_tmp.begin(); it != map_tmp.end(); it++)
			STREAM << *it;
	
		STREAM << "\nInserting an element with a hint in map_slow :\n";
		STREAM << "Need to add 1 million elements normally and then add 1 million elements with the hint, it goes way faster.\n";
	
		NS::map<int, int>	map_slow;
		for (int i = 0; i < 1000000; i++)
			map_slow.insert(NS::make_pair(i, 0));

		// NS::map<int, int>			map_fast;
		// map_fast[0] = 0;
		// NS::map<int, int>::iterator	prev(map_fast.begin());

		// for (int i = 0; i < 1000000; i++)
		// 	prev = map_fast.insert(prev, NS::make_pair(i, 0));
		
	STREAM << "\n	| CONSTRUCT MAP (with another map and iterators) AND OPERATOR = |\n\n";

	NS::map<int, int> map_copy(map_tmp);
	NS::map<int, int> map_copy2 = map_tmp;

	
	STREAM << "\n	| COMPARISON OPERATORS |\n\n";

	mappy.insert(NS::make_pair(40, 5));
	STREAM << "is map_copy == map_tmp ? " << (map_copy == map_tmp) << std::endl;
	STREAM << "is map_copy2 == map_tmp ? " << (map_copy2 == map_tmp) << std::endl;
	STREAM << "is mappy == map_tmp ? " << (mappy == map_tmp) << std::endl;
	STREAM << "is mappy != map_tmp ? " << (mappy != map_tmp) << std::endl;
	STREAM << "is mappy > map_tmp ? " << (mappy > map_tmp) << std::endl;
	STREAM << "is mappy <= map_tmp ? " << (mappy <= map_tmp) << std::endl;
	
	STREAM << "\n	| ITERATORS OF RED BLACK TREE |\n\n";

		for (NS::map<int, int>::iterator it = tree.begin(); it != tree.end(); it++)
			STREAM << "tree : " << *it;
			
		STREAM << "iterator begin() : " << *tree.begin();
		STREAM << "iterator rbegin() : " << *tree.rbegin();
		STREAM << "iterator ++begin() : " << *(++tree.begin());
		STREAM << "iterator end() : " << *tree.end();
		STREAM << "iterator --end() : " << *(--tree.end());

		STREAM << "\n-----------------------------------------\n " << std::endl;

		for (NS::map<int, int>::const_iterator it = tree.begin(); it != tree.end(); ++it)
			STREAM << "iterator : "<< *it;
		STREAM << "\niterator begin() (to check that begin didn't change) : " << *tree.begin() << std::endl;

		NS::map<std::string, std::string> v;
		for (int i = 0 ; i < 26; i++)	
			v.insert(NS::map<std::string, std::string>::value_type(std::string(1, 'a' + i), "yooo"));


	STREAM << "\n	| LOWER/UPPERBOUND & EQUAL_RANGE |\n\n";

		STREAM << "What is b's upperbound : " << *v.upper_bound("b");
		STREAM << "What is b's lowerbound : " << *v.lower_bound("b");
		STREAM << "b's equal_range :	 " << *v.equal_range("b").first;


	STREAM << "\n	| ERASE |\n\n";

		STREAM << "\n1. erasing first element of v (a, yooo) -> \n";
		v.erase(std::string(1,(char)('a')));
		print_v(v);

		STREAM << "\n2. erasing all elements except begin and end -> \n";
		v.erase(++v.begin(), --v.end());
		print_v(v);
	
		STREAM << "3. erasing the rest \n";
		v.erase(v.begin(), v.end());
		print_v(v);

	STREAM << "\n	| INSERT 1000 ELEMENTS TO MAP |\n\n";

		NS::map<int, int>	map1;

		for (int i = 0; i < 1000; i++)
			map1.insert(NS::make_pair(i, i * i));

		STREAM << "first element of map1 : " << *map1.begin();


	STREAM << "\n	| CLEAR |\n\n";

		map1.clear();
		STREAM << "cleared map1, is it empty ? " << map1.empty() << "\n\n";


	STREAM << "\n	| SWAP |\n\n";

		NS::swap(map1, map_tmp);
		STREAM << "swapped map1 with map_tmp, now map_tmp should be empty : " << map_tmp.empty() << "\n\n";
		for (NS::map<int, int>::iterator it = map1.begin(); it != map1.end(); it++)
			STREAM << "map1 : " << *it;

	STREAM << "\n	|----------------------|\n";
	STREAM << "	|                      |\n";
	STREAM << "	|          SET         |\n";
	STREAM << "	|                      |\n";
	STREAM << "	|----------------------|\n";		

	STREAM << "\n	| INSERT 100000 ELEMENTS TO SET |\n\n";

	NS::set<int>	set1;

	for (int i = 0; i < 100000; i++)
		set1.insert(i);

	STREAM << "last element of set1 : " << *--set1.end() << std::endl;
	
	// system("leaks ft_containers");
}


//~ ////////////////// MAIN 19 ///////////////// ~//


// #include <iostream>
// #include <string>
// #include <deque>
// #if 0 //CREATE A REAL STL EXAMPLE
//         #include <map>
//         #include <stack>
//         #include <vector>
//         namespace ft = std;
// #else
//         #include "map.hpp"
//         #include "stack.hpp"
//         #include "vector.hpp"
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
//         int idx;
//         char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
//         MutantStack() {}
//         MutantStack(const MutantStack<T>& src) { *this = src; }
//         MutantStack<T>& operator=(const MutantStack<T>& rhs) 
//         {
//                 this->c = rhs.c;
//                 return *this;
//         }
//         ~MutantStack() {}

//         typedef typename ft::stack<T>::container_type::iterator iterator;

//         iterator begin() { return this->c.begin(); }
//         iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
//         if (argc != 2)
//         {
//                 std::cerr << "Usage: ./test seed" << std::endl;
//                 std::cerr << "Provide a seed please" << std::endl;
//                 std::cerr << "Count value:" << COUNT << std::endl;
//                 return 1;
//         }
//         const int seed = atoi(argv[1]);
//         srand(seed);

//         ft::vector<std::string> vector_str;
//         ft::vector<int> vector_int;
//         ft::stack<int> stack_int;
//         ft::vector<Buffer> vector_buffer;
//         ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
//         ft::map<int, int> map_int;

//         for (int i = 0; i < COUNT; i++)
//         {
//                 vector_buffer.push_back(Buffer());
//         }

//         for (int i = 0; i < COUNT; i++)
//         {
//                 const int idx = rand() % COUNT;
//                 vector_buffer[idx].idx = 5;
//         }
//         ft::vector<Buffer>().swap(vector_buffer);

//         try
//         {
//                 for (int i = 0; i < COUNT; i++)
//                 {
//                         const int idx = rand() % COUNT;
//                         vector_buffer.at(idx);
//                         std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
//                 }
//         }
//         catch(const std::exception& e)
//         {
//                 //NORMAL ! :P
//         }

//         for (int i = 0; i < COUNT; ++i)
//         {
//                 map_int.insert(ft::make_pair(rand(), rand()));
//         }

//         int sum = 0;
//         for (int i = 0; i < 10000; i++)
//         {
//                 int access = rand();
//                 sum += map_int[access];
//         }
//         std::cout << "should be constant with the same seed: " << sum << std::endl;

//         {
//                 ft::map<int, int> copy = map_int;
//         }
//         MutantStack<char> iterable_stack;
//         for (char letter = 'a'; letter <= 'z'; letter++)
//                 iterable_stack.push(letter);
//         for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
//         {
//                 std::cout << *it;
//         }
//         std::cout << std::endl;
//         return (0);
// }