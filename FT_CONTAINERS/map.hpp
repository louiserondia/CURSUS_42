/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:08:03 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/28 18:41:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
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

template < class Key, class T, class Compare = less< Key >, 
			class Allocator = Allouloucator< std::pair< const Key, T > > >
class map {

	public :
	
	// ^----------------------------------------------------^
	// ^													^
	// ^					TYPEDEFS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		typedef Key												key_type;
		typedef	T												mapped_type;
		typedef std::pair<const Key, T>							value_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef typename Allocator::reference					reference;
		typedef typename Allocator::const_reference				const_reference;
		typedef typename Allocator::pointer						pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef typename std::map::iterator						iterator;
		typedef typename std::map::const_iterator				const_iterator;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename std::size_t							size_type;
		typedef typename std::ptrdiff_t							difference_type;
		
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
			const Compare &comp = Compare(), const Allocator & = Allocator()) {}

		map(const map< Key, T, Compare, Allocator> &x) {}

		~map() {}
	
		map<Key, T, Compare, Allocator>	&operator=(const map<Key, T, Compare, Allocator) {}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		ITERATORS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		CAPACITY			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
		bool		empty() const {}
		size_type	size() const {}
		size_type	max_size() const {}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	ELEMENT ACCESS			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
		T	&operator[](const key_type &x) {}
	
	// ^----------------------------------------------------^
	// ^													^
	// ^			 		MODIFIERS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		pair<iterator, bool>	insert(const value_type &x) {}
		
		iterator	insert(iterator position, const value_type &x) {}
		
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last) {}

		void	erase(iterator position) {}

		void	erase(const key_type &x) {}
		
		void	erase(iterator first, iterator last) {}
		
		void	swap(map<Key, T, Compare, Allocator> &) {}

		void	clear() {}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		OBSERVERS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		key_compare	key_comp() const {}
		
		value_compare	value_comp() const {}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	MAP OPERATIONS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		iterator	find(const key_type &x) {}
		
		const_iterator	find(const key_type &x) const {}
		
		size_type	count(const key_type &x) const {}

		iterator		lower_bound(const key_type &x) {}
		
		const_iterator	lower_bound(const key_type &x) const {}
		
		iterator		upper_bound(const key_type &x) {}
		
		const_iterator	upper_bound(const key_type &x) const {}
		
		pair<iterator, iterator>	equal_range(const key_type &x) {}

		pair<const_iterator, const_iterator>	equal_range(const key_type &x) const {}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	PRIVATE INSTANCES					^
	// ^													^
	// ^----------------------------------------------------^

	private:

};


// ^----------------------------------------------------^
// ^													^
// ^			 	COMPARAISON OVERLOADS				^
// ^													^
// ^----------------------------------------------------^		

	
}