/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:54:24 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/07 18:24:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "utility.hpp"
#include "Rbt.hpp"


// ^--------------------------------------------------------^
// ^				   ___     ___    _____  				^
// ^				  / __|   | __|  |_   _| 				^
// ^				  \__ \   | _|     | |   				^
// ^				  |___/   |___|   _|_|_  				^
// ^				_|"""""|_|"""""|_|"""""| 				^
// ^				"`-0-0-'"`-0-0-'"`-0-0-' 				^
// ^--------------------------------------------------------^


namespace ft {
	
template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
class set {

	public:

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		TYPEDEFS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

	typedef Rbt<Key, Key, Compare, typename Allocator::template 
			rebind< ft::pair<const Key, Key> >::other>	tree_type;
	typedef typename tree_type::iterator				tree_iterator;						
	typedef typename tree_type::const_iterator			tree_const_iterator;						

	typedef typename tree_type::key_type				key_type;
	typedef typename tree_type::key_type				value_type;
	typedef typename tree_type::key_compare				key_compare;
	typedef typename tree_type::key_compare				value_compare;
	typedef Allocator									allocator_type;
	typedef typename tree_type::size_type				size_type;
	typedef typename tree_type::difference_type			difference_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		ITERATORS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

	class	Iterator {
	
		public:

		typedef set::value_type									value_type;
		typedef set::const_pointer								pointer;
		typedef set::const_reference							reference;
		typedef typename tree_const_iterator::difference_type	difference_type;
		typedef typename tree_const_iterator::iterator_category	iterator_category;

		private:
			tree_const_iterator	_it;

		public:

			Iterator() : _it(tree_const_iterator()) {}
			Iterator(const Iterator &other) : _it(other._it) {}
			Iterator(const tree_iterator &other) : _it(other) {}
			Iterator(const tree_const_iterator &other) : _it(other) {}
			Iterator &operator=(const Iterator &other) {
				_it = other._it;
				return *this;
			}

			Iterator &operator++() {
				_it++;
				return *this;
			}
			
			Iterator  operator++(int) { return _it++; }

			Iterator &operator--() {
				_it--;
				return *this;
			}

			Iterator operator--(int) { return _it--; }

			reference operator*() const { return _it->second; }
			
			pointer   operator->() const { return &_it->second; }

			bool operator==(const Iterator &other) const { return _it == other._it; }

			bool operator==(const tree_const_iterator &other) const { return _it == other; }
			
			bool operator==(const tree_iterator &other) const { return _it == other; }
			
			bool operator!=(const Iterator &other) const { return _it != other._it; }
			
			bool operator!=(const tree_const_iterator &other) const { return _it != other; }
			
			bool operator!=(const tree_iterator &other) const { return _it != other; }

			operator tree_const_iterator() const { return _it; }
		
	};

    typedef Iterator								iterator;
    typedef Iterator								const_iterator;
    typedef ft::reverse_iterator< iterator >		reverse_iterator;
    typedef ft::reverse_iterator< const_iterator >	const_reverse_iterator;

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
	// ^			 		 MEMBER				 		 	^
	// ^													^
	// ^----------------------------------------------------^

private:

	tree_type	_tree;

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	 DE/CONSTRUCTORS					^
	// ^													^
	// ^----------------------------------------------------^

public:

	explicit set(const Compare &comp = Compare(), const Allocator &alloc = Allocator())
		: _tree(comp, alloc) {}

	template <class InputIterator>
	set(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator()) 
		: _tree(comp, alloc) { insert(first, last); }

	set(const set &x) : _tree(x._tree) {}

	~set() {}
	
	set	&operator=(const set &x) {
		_tree = x._tree;
		return *this;
	}

	// ^----------------------------------------------------^
	// ^													^
	// ^		 			ALLOCATOR						^
	// ^													^
	// ^----------------------------------------------------^

	allocator_type	get_allocator() const { return _tree.get_allocator(); }

	// ^----------------------------------------------------^
	// ^													^
	// ^		 			CAPACITY						^
	// ^													^
	// ^----------------------------------------------------^

	bool empty() const { return !size(); }
	size_type size() const { return _tree.size(); }
	size_type max_size() const { return _tree.max_size(); }


	// ^----------------------------------------------------^
	// ^													^
	// ^		 			MODIFIERS						^
	// ^													^
	// ^----------------------------------------------------^
	
	ft::pair<iterator,bool> insert(const value_type& x) { 
		return _tree.insert(ft::make_pair(x, x));
	}
	
	iterator insert(iterator position, const value_type& x) {
		return _tree.insert(tree_const_iterator(position).get_node(), ft::make_pair(x, x)).first;
	}
	
	template <class InputIterator>
	void insert(InputIterator first, InputIterator last) {
		for ( ; first != last; first++)
			insert(*first);
	}

	void erase(iterator position) { _tree.erase(*position); }
	
	size_type erase(const key_type& x) { return _tree.erase(x); }
	
	void erase(iterator first, iterator last) {
			while (first != last) {
           		iterator tmp = ++(iterator(first));
            erase(first);
            first = tmp;
        }
	}
	
	void swap(set<Key,Compare,Allocator> &other) { _tree.swap(other._tree); }
	
	void clear() { _tree.clear(); }

	// ^----------------------------------------------------^
	// ^													^
	// ^		 		KEY/VALUE COMP						^
	// ^													^
	// ^----------------------------------------------------^

	key_compare key_comp() const { return key_compare(); }
	
	value_compare value_comp() const { return value_compare(); }	

	// ^----------------------------------------------------^
	// ^													^
	// ^		 		SET OPERATIONS						^
	// ^													^
	// ^----------------------------------------------------^
	
	iterator	find(const key_type& x) const { return _tree.find(x); }
	
	size_type	count(const key_type& x) const { return _tree.count(x); }
	
	iterator	lower_bound(const key_type& x) const { return _tree.lower_bound(x); }
	
	iterator	upper_bound(const key_type& x) const { return _tree.upper_bound(x); }
	
	pair<iterator,iterator> equal_range(const key_type& x) const { 
		return ft::pair<iterator, iterator>(lower_bound(x), upper_bound(x));
	}

	// ^----------------------------------------------------^
	// ^													^
	// ^		 		COMPARISON OPERATORS				^
	// ^													^
	// ^----------------------------------------------------^

	bool	operator==(const set &other) const {
		return _tree == other._tree;
	}

	bool	operator!=(const set &other) const {
		return _tree != other._tree;
	}

	bool	operator<(const set &other) const {
		return _tree < other._tree;
	}

	bool	operator>(const set &other) const {
		return _tree > other._tree;
	}

	bool	operator<=(const set &other) const {
		return _tree <= other._tree;
	}

	bool	operator>=(const set &other) const {
		return _tree >= other._tree;
	}

};

	// ^----------------------------------------------------^
	// ^													^
	// ^		 		SPECIALIZED ALGORITHM				^
	// ^													^
	// ^----------------------------------------------------^

	template <class Key, class Compare, class Allocator>
	void swap(set<Key,Compare,Allocator> &x, set<Key,Compare,Allocator>& y) {
		x.swap(y);
	}

}