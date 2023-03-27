/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:08:03 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/27 12:06:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <functional>
#include <utility>
#include "utility.hpp"
#include "Allouloucator.hpp"

// ^--------------------------------------------------------^
// ^	   			  __  __    ___      ___  				^
// ^	   			 |  \/  |  /   \    | _ \ 				^
// ^	   			 | |\/| |  | - |    |  _/ 				^
// ^	   			 |_|__|_|  |_|_|   _|_|_  				^
// ^	   			 _|"""""|_|"""""|_| """ | 				^
// ^	   			 "`-0-0-'"`-0-0-'"`-0-0-' 				^
// ^--------------------------------------------------------^

namespace ft {

template < class Key, class T, class Compare = std::less< Key >, 
			class Allocator = Allouloucator< ft::pair< const Key, T > > >
class map {

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	  MEMBER ELEMENTS					^
	// ^													^
	// ^----------------------------------------------------^

	private:

		tree_type	_tree;

	public :
	
	// ^----------------------------------------------------^
	// ^													^
	// ^					TYPEDEFS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		typedef typename tree_type::key_type					key_type;
		typedef typename tree_type::mapped_type					mapped_type;
		typedef typename tree_type::value_type					value_type;
		typedef typename tree_type::value_type					value_type;
		typedef typename tree_type::key_compare					key_compare;;
		typedef typename tree_type::allocator_type				allocator_type;
		typedef typename tree_type::reference					reference;
		typedef typename tree_type::const_reference				const_reference;
		typedef typename tree_type::pointer						pointer;
		typedef typename tree_type::const_pointer				const_pointer;
		typedef typename std::size_t							size_type;
		typedef typename std::ptrdiff_t							difference_type;
		//? pas ici les iterators ?

		
		struct value_compare : public std::binary_function< value_type, value_type, bool> {
			friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}
			public:
				bool	operator()(const value_type &x, const value_type &y) const {
					return comp(x.first, y.first);
				}
		};

	// ^----------------------------------------------------^
	// ^													^
	// ^		 CONSTRUCTOR / DESTRUCTOR / ASSIGN		 	^
	// ^													^
	// ^----------------------------------------------------^	

		explicit map(const Compare &comp = Compare(), const Allocator & = Allocator()) {}
		
		template <class InputIterator>
		map(InputIterator first, InputIterator last, 
			const Compare &comp = Compare(), const Allocator &alloc = Allocator()) : _tree( tree_type(comp, alloc)) {
				insert(first, last);
			}

		map(const map &other) : _tree(other._tree) {}

		~map() {}
	
		// map<Key, T, Compare, Allocator>	&operator=(const map<Key, T, Compare, Allocator) {}
		// pas besoin de preciser les templates comme on est dans le scope de la classe ?
		
		map	&operator=(const map &other) {
			_tree = other._tree;
			return *this;
		}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		ITERATORS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		iterator				begin() { return _tree.begin(); }
		const_iterator			begin() const { return _tree.begin(); }
		iterator				end() { return _tree.end(); }
		const_iterator			end() const { return _tree.end(); }
		reverse_iterator		rbegin() { return _tree.rbegin(); }
		const_reverse_iterator	rbegin() const { return _tree.rbegin(); }
		reverse_iterator		rend() { return _tree.rend(); }
		const_reverse_iterator	rend() const { return _tree.rend(); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		CAPACITY			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
		bool		empty() const { return !size(); }
		size_type	size() const { return _tree.size(); }
		size_type	max_size() const { return _tree.max_size(); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	ELEMENT ACCESS			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
		T	&operator[](const key_type &x) {}
		
		//	at ?
	
	// ^----------------------------------------------------^
	// ^													^
	// ^			 		MODIFIERS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		pair<iterator, bool>	insert(const value_type &x) { return _tree.insert(x); }
		
		iterator	insert(iterator position, const value_type &x) { return _tree.insert(position, x).first; }
		
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last) { return _tree.insert(first, last).first; }
		
		void	erase(iterator position) { return _tree.erase(position->first); }

		void	erase(const key_type &x) { return _tree.erase(x); }
		
		void	erase(iterator first, iterator last) { return _tree.erase(first, last); }
		
		void	swap(map &other) { ft::swap(_tree, other._tree); }

		void	clear() { _tree.clear(); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		OBSERVERS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		key_compare	key_comp() const { return key_compare(); }
		
		value_compare	value_comp() const { return value_compare(); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	MAP OPERATIONS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		iterator		find(const key_type &x) { return _tree.find(x); }
		
		const_iterator	find(const key_type &x) const { return _tree.find(x); }
		
		size_type		count(const key_type &x) const { return _tree.count(x); }

		iterator		lower_bound(const key_type &x) { return _tree.lower_bound(x); }
		
		const_iterator	lower_bound(const key_type &x) const { return _tree.lower_bound(x); }
		
		iterator		upper_bound(const key_type &x) { return _tree.upper_bound(x); }
		
		const_iterator	upper_bound(const key_type &x) const { return _tree.upper_bound(x); }
		
		ft::pair<iterator, iterator>	equal_range(const key_type &x) {
			return ft::pair<iterator, iterator>(lower_bound(x), upper_bound(x));
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const key_type &x) const {
			return ft::pair<const_iterator, const_iterator>(lower_bound(x), upper_bound(x));
		}

};


// ^----------------------------------------------------^
// ^													^
// ^			 	COMPARAISON OVERLOADS				^
// ^													^
// ^----------------------------------------------------^		

	template <class Key, class T, class Compare, class Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y) {}

	template <class Key, class T, class Compare, class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y) {}

	template <class Key, class T, class Compare, class Allocator>
	bool	operator<(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y) {}

	template <class Key, class T, class Compare, class Allocator>
	bool	operator>(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y) {}

	template <class Key, class T, class Compare, class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y) {}

	template <class Key, class T, class Compare, class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator> &x, const map<Key, T, Compare, Allocator> &y) {}

	template <class Key, class T, class Compare, class Allocator>
	void	swap(map<Key, T, Compare, Allocator> &x, map<Key, T, Compare, Allocator> &y) {}
	
}