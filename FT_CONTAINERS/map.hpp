/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:08:03 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/06 18:20:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <functional>
#include <utility>
#include "utility.hpp"
#include "Allouloucator.hpp"
#include "Rbt.hpp"

// ^--------------------------------------------------------^
// ^	   			  __  __    ___      ___  				^
// ^	   			 |  \/  |  /   \    | _ \ 				^
// ^	   			 | |\/| |  | - |    |  _/ 				^
// ^	   			 |_|__|_|  |_|_|   _|_|_  				^
// ^	   			 _|"""""|_|"""""|_| """ | 				^
// ^	   			 "`-0-0-'"`-0-0-'"`-0-0-' 				^
// ^--------------------------------------------------------^

namespace ft {

template <	class Key,
			class Value,
			class Compare = std::less< Key >, 
			class Allocator = std::allocator< ft::pair< const Key, Value > > >
class map {

	// ^----------------------------------------------------^
	// ^													^
	// ^					TYPEDEFS			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
	public :


		typedef typename ft::Rbt<Key, Value, Compare, Allocator>	tree_type;
    	typedef typename tree_type::iterator                 		tree_iterator;
    	typedef typename tree_type::const_iterator          		tree_const_iterator;
		typedef typename tree_type::key_type						key_type;
		typedef typename tree_type::mapped_type						mapped_type;
		typedef typename tree_type::value_type						value_type;
		typedef typename tree_type::key_compare						key_compare;;
		typedef typename tree_type::allocator_type					allocator_type;
		typedef typename tree_type::reference						reference;
		typedef typename tree_type::const_reference					const_reference;
		typedef typename tree_type::pointer							pointer;
		typedef typename tree_type::const_pointer					const_pointer;
		typedef typename std::size_t								size_type;
		typedef typename std::ptrdiff_t								difference_type;


		
		struct value_compare {//} : public std::binary_function< value_type, value_type, bool> {
			
			// friend class map;
			
			// protected:
			
			// 	Compare	comp;
			// 	value_compare(Compare c) : comp(c) {}
			
			// public:
			
				bool	operator()(const value_type &x, const value_type &y) const {
					return key_compare()(x.first, y.first);
				}

		};

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	  MEMBER ELEMENTS					^
	// ^													^
	// ^----------------------------------------------------^

	private:

		tree_type	_tree;

	// ^----------------------------------------------------^
	// ^													^
	// ^		 CONSTRUCTOR / DESTRUCTOR / ASSIGN		 	^
	// ^													^
	// ^----------------------------------------------------^	

	public:

		explicit map(const Compare &comp = Compare(), const Allocator &alloc = Allocator()) :
			_tree(tree_type(comp, alloc))
		{}
		
		template <class InputIterator>
		map(InputIterator first, InputIterator last, const Compare &comp = Compare(), const Allocator &alloc = Allocator()) : 
			_tree(tree_type(comp, alloc)) {
			insert(first, last);
		}

		map(const map &other) : _tree(other._tree) {}

		~map() {}
	
		// map<Key, Value, Compare, Allocator>	&operator=(const map<Key, Value, Compare, Allocator) {}
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

	template <typename T>
	class	Iterator {
	
		public:

		typedef typename T::value_type			value_type;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;

		private:
			T	_it;

		public:

			Iterator() : _it(T()) {}
			Iterator(const Iterator &other) : _it(other._it) {}
			Iterator(const T &other) : _it(other) {}
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

			reference operator*() const { return *_it; }
			
			pointer   operator->() const { return _it.operator->(); }

			template <typename U>
			bool operator==(const Iterator<U> &other) const {
				return T( *this ) == U(other );
			}
			
			bool operator==(const T &other) const { return T(*this) == other; }
			
			template <typename U>
			bool operator!=(const Iterator<U> &other) const {
				return !(*this == other);
			}
			
			bool operator!=(const T &other) const { return !(*this == other); }

			operator T() const { return T(_it); }
			
			operator Iterator<tree_const_iterator>() const {
				return Iterator<tree_const_iterator>(_it);
			}
		
	};

	    typedef Iterator< tree_iterator >				iterator;
		typedef Iterator< tree_const_iterator >			const_iterator;
		typedef ft::reverse_iterator< iterator >		reverse_iterator;
		typedef ft::reverse_iterator< const_iterator > 	const_reverse_iterator;


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
	
		mapped_type	&operator[](const key_type &k) {
			return _tree.insert(value_type(k, mapped_type())).first->second;
		}
		// insert renvoie une pair avec un iterateur et un boolean, 
		// on va donc chercher la valeur (donc second) de l'iterateur (qui est first)
		
		mapped_type	&at(const key_type& k) {
			iterator	find = find(k);
			if (find == end())
				throw(std::out_of_range("aïe: "));
			return find->second;
		}

		const mapped_type	&at(const key_type& k) const {
			const_iterator	find = find(k);
			if (find == end())
				throw(std::out_of_range("aïe: "));
			return find->second;
		}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		ALLOCATOR			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		allocator_type	get_allocator() const { return _tree.get_allocator(); }
	
	// ^----------------------------------------------------^
	// ^													^
	// ^			 		MODIFIERS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		pair<iterator, bool>	insert(const value_type &x) { return _tree.insert(x); }
		
		iterator	insert(iterator position, const value_type &x) { return _tree.insert(position, x).first; }
		
		template <class InputIterator>
		void	insert(InputIterator first, InputIterator last) { _tree.insert(first, last); }
		
		void	erase(iterator position) { _tree.erase(position->first); }

		size_type	erase(const key_type &x) { return _tree.erase(x); }
		
		void	erase(iterator first, iterator last) { _tree.erase(first, last); }
		
		void	swap(map &other) { _tree.swap(other._tree); }

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

// ^----------------------------------------------------^
// ^													^
// ^			 	COMPARAISON OVERLOADS				^
// ^													^
// ^----------------------------------------------------^		
	

	bool	operator==(const map &other) const {
		return _tree == other._tree;
	}

	bool	operator!=(const map &other) const {
		return _tree != other._tree;
	}

	bool	operator<(const map &other) const {
		return _tree < other._tree;
	}

	bool	operator>(const map &other) const {
		return _tree > other._tree;
	}

	bool	operator<=(const map &other) const {
		return _tree <= other._tree;
	}

	bool	operator>=(const map &other) const {
		return _tree >= other._tree;
	}


};
	template <class Key, class Value, class Compare, class Allocator>
	void	swap(map< Key, Value, Compare, Allocator> &x, map< Key, Value, Compare, Allocator> &y) {
		x.swap(y);
	}

}