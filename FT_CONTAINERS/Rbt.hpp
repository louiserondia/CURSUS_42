/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/07 18:27:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "utility.hpp"
#include "Allouloucator.hpp"
#include "reverse_iterator.hpp"

namespace ft {


// *-------------------------------------------------------------------------------------------------------------------------*
// *																														 *
// *	   ___     ___     ___              ___     _       ___     ___    _  __            _____    ___     ___     ___  	 *
// *	  | _ \   | __|   |   \     o O O  | _ )   | |     /   \   / __|  | |/ /     o O O |_   _|  | _ \   | __|   | __| 	 *
// *	  |   /   | _|    | |) |   o       | _ \   | |__   | - |  | (__   | ' <     o        | |    |   /   | _|    | _|  	 *
// *	  |_|_\   |___|   |___/   TS__[O]  |___/   |____|  |_|_|   \___|  |_|\_\   TS__[O]  _|_|_   |_|_\   |___|   |___| 	 *
// *	_|"""""|_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| {======|_|"""""|_|"""""|_|"""""|_|"""""|	 *
// *	"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'	 *
// *																														 *
// *-------------------------------------------------------------------------------------------------------------------------*

template <	typename Key,
			typename Value,
			typename Comp = std::less<Key>,
			typename Allocator = std::allocator<ft::pair<const Key, Value> > >

class	Rbt {

// *----------------------------------------------------*
// *													*
// *					  TYPEDEFS	 		 			*
// *													*
// *----------------------------------------------------*

public:

	typedef Key                                     	key_type;
	typedef Value										mapped_type;
	typedef ft::pair< const key_type, mapped_type >		value_type;
	typedef Comp										key_compare;
	typedef Allocator									allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef std::ptrdiff_t								difference_type;
	typedef std::size_t									size_type;

// ~----------------------------------------------------~
// ~----------------------------------------------------~
// ~													~
// ~													~
// ~					   NODE						 	~
// ~													~
// ~													~
// ~----------------------------------------------------~
// ~----------------------------------------------------~
// ~													~
// ~					  MEMBERS			 		 	~
// ~													~
// ~----------------------------------------------------~
// ~----------------------------------------------------~

private: 
	
	struct _Node {
	
		value_type	data;
		_Node		*left;
		_Node		*right;
		_Node		*parent;
		bool		red;
		bool		is_nil;

// ~----------------------------------------------------~
// ~													~
// ~				  CON/DESTRUCTORS			 	 	~
// ~													~
// ~----------------------------------------------------~
	
	public :

		typedef typename Allocator::template rebind<_Node>::other	node_allocator_type;
		typedef typename node_allocator_type::pointer				node_pointer;

		_Node() :
			data(value_type()),
			left(0),
			right(0),
			parent(0),
			red(false),
			is_nil(false) {}

		_Node(bool is_red, node_pointer left, node_pointer right) : 
			data(),
			left(left),
			right(right),
			parent(0),
			red(is_red),
			is_nil(false) {}

		_Node(bool is_red, const value_type &value = value_type()) : 
			data(value), 
			left(0), 
			right(0), 
			parent(0), 
			red(is_red),
			is_nil(false) {}

		_Node(const _Node &other) :
			data(other.data), 
			left(other.left), 
			right(other.right), 
			parent(other.parent), 
			red(other.red),
			is_nil(other.is_nil) {}

		node_pointer	clone(node_allocator_type &alloc) const {
			node_pointer	node = alloc.allocate(1);
			alloc.construct(node, *this);
			return node;
		}

		static void destroy(node_pointer node, node_allocator_type &node_alloc) {
			node_alloc.destroy(node);
			node_alloc.deallocate(node, 1);
		}

// ~----------------------------------------------------~
// ~													~
// ~				COMPARASION OPERATORS	 		 	~
// ~													~
// ~----------------------------------------------------~

		bool operator==(const _Node &other) const {
			return data == other.data && left == other.left && right == other.right &&
				parent == other.parent && red == other.red && is_nil == other.is_nil;
		}

		bool operator!=(const _Node &other) const {
			return !(*this == other);
		}
		
	};

public:

	typedef _Node								node_type;
	typedef typename _Node::node_allocator_type	node_allocator_type;
	typedef typename _Node::node_pointer		node_pointer;

// *----------------------------------------------------*
// *----------------------------------------------------*
// *													*
// *													*
// *				RED BLACK TREE					 	*
// *													*
// *													*
// *----------------------------------------------------*
// *----------------------------------------------------*
// *													*
// *				EXTENDED KEY COMPARE	 		 	*
// *													*
// *----------------------------------------------------*

// We use key_compare to compare different element instead of using their < and > operators
// Extended key compare uses key_compare but also compare _end and _rend which
// will always be bigger and smaller than what we try to compare, 
// that way they stay on the very left and right side of the tree
// It is a functor so we use its operator() to do the comparison	

struct	extended_key_compare {
	private:

		node_pointer	_end;
		node_pointer	_rend;
		key_compare		_comp;

	public:
	
		extended_key_compare(node_pointer end, node_pointer rend, const key_compare &comp = key_compare()) :
			_end(end), _rend(rend), _comp(comp) {}
		
		bool	operator()(const key_type &a, const key_type &b) const { return _comp(a, b); }

		bool	operator()( const key_type &a, const node_pointer &b ) const {
            if ( b == _end )
				return true;
            if ( b == _rend )
				return false;
            return _comp( a, b->data.first );
        }
        bool	operator()( const node_pointer &a, const key_type &b ) const {
            if (a == _end)
				return false;
            if (a == _rend)
				return true;
            return _comp( a->data.first, b );
        }
		
        const key_compare	&key_comp() const { return _comp; }

};

// *----------------------------------------------------*
// *													*
// *					MEMBERS						 	*
// *													*
// *----------------------------------------------------*

private:

	node_allocator_type		_node_allocator;
	node_pointer			_nil;
	allocator_type			_allocator;
	node_pointer			_end;
	node_pointer			_rend;
	node_pointer			_head;
	extended_key_compare	_key_compare;
	size_type				_size;

// *----------------------------------------------------*
// *													*
// *				 CON/DESTRUCTORS				 	*
// *													*
// *----------------------------------------------------*

public:

	Rbt(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) :
		_node_allocator(alloc), 
		_nil(node_type(false, 0, 0).clone(_node_allocator)), 
		_allocator(alloc), 
		_end(node_type(false, _nil, _nil).clone(_node_allocator)),
		_rend(node_type(false, _nil, _nil).clone(_node_allocator)),
		_head(_end),
		_key_compare(extended_key_compare(_end, _rend, comp)),
		_size(0) {
		_head->parent = _nil;
		_head->left = _rend;
		_rend->red = true;
		_rend->parent = _head;
		_nil->is_nil = true;
	}		
	
	Rbt(const Rbt &other) :
		_node_allocator(other._node_allocator), 
		_nil(node_type(false, 0, 0).clone(_node_allocator)), 
		_allocator(other._allocator), 
		_end(node_type(false, _nil, _nil).clone(_node_allocator)),
		_rend(node_type(false, _nil, _nil).clone(_node_allocator)),
		_head(_end),
		_key_compare(extended_key_compare(_end, _rend, other._key_compare.key_comp())),
		_size(0) {
		_head->parent = _nil;
		_nil->is_nil = true;
		_head->left = _rend;
		_rend->red = true;
		_rend->parent = _head;
		insert(other.begin(), other.end());
	}
	
	Rbt &operator=(const Rbt& other) {
		clear();
		for (const_iterator it = other.begin(); it != other.end(); it++) {
			insert(*it);
		}
		return *this;
	}
	
	~Rbt() {
		clear();
		_Node::destroy(_nil, _node_allocator);
		_Node::destroy(_end, _node_allocator);
		_Node::destroy(_rend, _node_allocator);
	}


// *----------------------------------------------------*
// *													*
// *				 RBT ITERATOR					 	*
// *													*
// *----------------------------------------------------*

	template <typename T>
	struct Iterator {

	public:
	
		typedef	T								value_type;
		typedef	T &								reference;
		typedef T *								pointer;
		typedef std::ptrdiff_t					difference_type;
		typedef std::bidirectional_iterator_tag	iterator_category;

	private:

		node_pointer _node;

	public:

		Iterator() : _node(0) {}
		Iterator(node_pointer node) : _node(node) {}
		Iterator(const Iterator &other) : _node(other._node) {}
		Iterator	&operator=(const Iterator &other) {
			_node = other._node;
			return *this;
		}
		
		const node_pointer	&get_node() const { return _node; }

		// pour avancer depuis une node, on va essayer d'aller à son enfant de droite et ensuite le plus à gauche possible
		// si on n'a pas d'enfant de droite et qu'on est un enfant de gauche on va remonter au niveau du parent
		// et si on n'a ni enfant de droite et qu'on est nous-même un enfant de droite, alors on va remonter 
		// jusqu'à trouver une node qui est enfant de gauche et alors on se positione sur son parent (si il n'est pas _nil)

		Iterator	&operator++() {
			if (_node->right->is_nil == false) {
				_node = _node->right;
				while (_node->left->is_nil == false)
					_node = _node->left;
			}
			else {
					node_pointer	tmp = _node;
					while (tmp->parent->is_nil == false && tmp != tmp->parent->left)
						tmp = tmp->parent;
					if (tmp->parent->is_nil == false)
						_node = tmp->parent;
			}
			return *this;
		}
			
		Iterator	operator++(int) {
			Iterator	tmp(*this);
			
			++*this;
			return tmp;
		}

		Iterator			operator+(difference_type n) { 
			for (difference_type i = 0; i < n; i++)
				++*this;
			return *this;
		}

		friend Iterator		operator+(difference_type lhs, const Iterator &rhs) {
			for (difference_type i = 0; i < lhs; i++)
				++rhs;
			return rhs;
		}

		Iterator	&operator--() {
			if (_node->left->is_nil == false) {
				_node = _node->left;
				while (_node->right->is_nil == false)
					_node = _node->right;
			}
			else {
					node_pointer	tmp = _node;
					while (tmp->parent->is_nil == false && tmp != tmp->parent->right)
						tmp = tmp->parent;
					if (tmp->parent->is_nil == false)
						_node = tmp->parent;
			}
			return *this;
		}

		Iterator	operator--(int) {
			Iterator	tmp(*this);
			
			--*this;
			return tmp;
		}
		
		template <typename U>
		bool	operator==(const Iterator<U> &other) const {
			return _node == other.get_node();
		}
		
		template <typename U>
		bool	operator!=(const Iterator<U> &other) const {
			return !(*this == other);
		}

		reference	operator*() const { return _node->data; }
		pointer		operator->() const { return &_node->data; }

		operator Iterator<const T>() const { return Iterator<const T>(_node); }

	};

public:

	typedef	Iterator<value_type>					iterator;
	typedef	Iterator<const value_type>				const_iterator;
	typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	iterator				begin() { return ++iterator(_rend); }
	const_iterator			begin() const { return ++iterator(_rend); }
	iterator				end() { return _end; }
	const_iterator			end() const { return _end; }
	reverse_iterator		rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator	rbegin() const { return end(); }
	reverse_iterator		rend() { return reverse_iterator(begin()); }
	const_reverse_iterator	rend() const { return begin(); }


// *----------------------------------------------------*
// *													*
// *					  INSERT					 	*
// *													*
// *----------------------------------------------------*

	ft::pair<iterator, bool>	insert(const value_type newData) {
		return _insert(_head, newData);
	}

	ft::pair<iterator, bool>	insert(iterator hint, const value_type &newData) {
		if (_is_upper_bound(hint, newData.first))
			return _insert(hint.get_node(), newData);
		return _insert(_head, newData);
	}

	template <class InputIterator>
 	void	insert(InputIterator first, InputIterator last) {
		for ( ; first != last; first++)
			insert(*first);
	}

private:

	node_type	*_add_new_node(value_type newData, bool is_red) {
		node_type	*node = new node_type(is_red, newData);
		
		node->left = _nil;
		node->right = _nil;
		_size++;
		return node;
	}

	void	_insert_fixup(node_pointer node) {
		if (node == _head || !node->parent->red) // si parent est noir ou node est la tete
			return;
		if (node->parent == node->parent->parent->right) //~ tante de gauche
		{
			node_type	*aunt = node->parent->parent->left;

			//~ tante est rouge
			if (aunt->red) {
				aunt->red = false;
				node->parent->parent->red = true;
				node->parent->red = false;
				return _insert_fixup(node->parent->parent);
			}
			else {	//~ tante est noire
				if (node == node->parent->left) {
					//* triangle
					rotate_right(node->parent);
					node = node->right;
				}
				//* ligne
				rotate_left(node->parent->parent);
				node->parent->red = false;
				node->parent->left->red = true;
			}
		}
		else { //~ tante de droite
			node_type	*aunt = node->parent->parent->right;
			
			//~ tante est rouge
			if (aunt->red) {
				aunt->red = false;
				node->parent->parent->red = true;
				node->parent->red = false;
				return _insert_fixup(node->parent->parent);
			}
			else {	//~ tante est noire
				if (node == node->parent->right) {
					//* triangle
					rotate_left(node->parent);
					node = node->left;
				}
				//* ligne
				rotate_right(node->parent->parent);
				node->parent->red = false;
				node->parent->right->red = true;
			}
		}
		_head->red = false;
	}

	ft::pair<node_pointer, bool>	_insert(node_pointer node, const value_type newData) {
		node_pointer	copy;
		
		if (!_size) {
			node = _add_new_node(newData, 0);
			_head = node;
			_head->left = _rend;
			_rend->parent = _head;
			_head->right = _end;
			_end->parent = _head;
			_end->red = true;
			_end->left = _nil;
			_rend->right = _nil;
			return ft::make_pair(node, true);
		}
		if (_key_compare(newData.first, node)) {
			if (node->left != _nil)
				return _insert(node->left, newData);
			node->left = _add_new_node(newData, 1);
			node->left->parent = node;
			copy = node->left;
			_insert_fixup(node->left);
			return ft::make_pair(copy, true);
		}
		else if (_key_compare(node, newData.first)) {
			if (node->right != _nil)
				return _insert(node->right, newData);
			node->right = _add_new_node(newData, 1);
			node->right->parent = node;
			copy = node->right;
			_insert_fixup(node->right);
			return ft::make_pair(copy, true);
		}
		return ft::make_pair(node, false);
	}

// *----------------------------------------------------*
// *													*
// *					REMOVE				 		 	*
// *													*
// *----------------------------------------------------*

public:
		
	node_type	*get_biggest_node(node_pointer node) {
		node_type	*copy = node;

		while (copy != _nil && copy->right != _nil) {
			copy = copy->right;
		}
		return copy;
	}

	node_type	*get_smallest_node(node_pointer node) {
		node_type	*copy = node;

		while (copy != _nil && copy->left != _nil) {
			copy = copy->left;
		}
		return copy;
	}

	void	_transplant(node_pointer from, node_pointer to) {
		from->parent = to->parent;
		if (to == _head)
			_head = from;
		else if (to == to->parent->left)
			to->parent->left = from;
		else
			to->parent->right = from;
	}
	
private:

	void	_remove_fixup(node_pointer x) {
		if (x == _head || x->red) {
			x->red = false;
			return;
		}
		//x est enfant de G ou D
		if (x == x->parent->left) {
			node_type	*sista = x->parent->right;
			//si la soeur est rouge
			if (sista->red) {
				sista->red = false;
				x->parent->red = true;
				rotate_left(x->parent);
				return _remove_fixup(x);
			}
			// soeur est noire
			if (!sista->left->red && !sista->right->red) { // les enfants de la soeur sont noirs
				sista->red = true;
				return _remove_fixup(x->parent);
			}

			if (!sista->right->red) { // si le neveu proche est rouge et lointain est noir
				sista->red = true;
				sista->left->red = false;
				rotate_right(sista);
				sista = x->parent->right;
			}
			// si le neveu lointain est rouge (et l'autre p-e aussi)
			sista->red = x->parent->red;
			x->parent->red = false;
			sista->right->red = false;
			rotate_left(x->parent);
		}
		else {
			node_type	*sista = x->parent->left;
			// soeur est rouge
			if (sista->red) {
				sista->red = false;
				x->parent->red = true;
				rotate_right(x->parent);
				return _remove_fixup(x);
			}
			// soeur est noire
			if (!sista->right->red && !sista->left->red) { // enfants de la soeur sont noirs
				sista->red = true;
				return _remove_fixup(x->parent);
			}
			if (!sista->left->red) { // neveu proche est rouge et lointain est noir
				sista->red = true;
				sista->right->red = false;
				rotate_left(sista);
				sista = x->parent->left;
			}
			// si le neveu lointain est rouge
			sista->red = x->parent->red;
			x->parent->red = false;
			sista->left->red = false;
			rotate_right(x->parent);
		}
	}

	size_type	_remove(node_pointer node) {
		node_pointer	z = node;
		node_pointer	y = z;
		node_pointer	x;
		bool			y_origin_color = y->red;
		
		if (node == _nil || node == _end) {
			return 0;
		}
		if (z->left == _nil) {
			x = z->right;
			_transplant(x, z);
		}
		else if (z->right == _nil) {
			x = z->left;
			_transplant(x, z);
		}
		else {
			y = get_smallest_node(z->right);
			x = y->right;
			_transplant(x, y);
			_transplant(y, z);
			y->left = z->left;
			z->left->parent = y;
			y->right = z->right;
			z->right->parent = y;
			y_origin_color = y->red;
			y->red = z->red;
		}
		if (!y_origin_color) //y est noir
			_remove_fixup(x);
		_Node::destroy(z, _node_allocator);
		_size--;
		return 1;
	}


// *----------------------------------------------------*
// *													*
// *			 		CAPACITY			 		 	*
// *													*
// *----------------------------------------------------*

public:

	size_type	size() const { return _size; }
	size_type	max_size() const { return _allocator.max_size(); }

private:

	// to check the height of the red back tree
	// size_type	height() { return _height(_head); }
	size_type	_height(_Node *node) {
		if (node == _nil) {
			return 0;
		}
		return 1 + std::max(_height (node->left), _height(node->right));
	}


// *----------------------------------------------------*
// *													*
// *				  FIND + COUNT	 				 	*
// *													*
// *----------------------------------------------------*

public:

	iterator	find(const key_type key) {
		return _find(_head, key);
	}

	const_iterator	find(const key_type key) const {
		return _find(_head, key);
	}

	iterator	_find(node_pointer node, const key_type key) const {
		if (node == _nil)
			return _end;
		if (_key_compare(key, node))
			return _find(node->left, key);
		if (_key_compare(node, key))
			return _find(node->right, key);
		return node;
	}

	size_type	count(const key_type key) const {
		return _find(_head, key).get_node() != _end;
	}

// *----------------------------------------------------*
// *													*
// *				  LOWER/UPPERBOUND	 			 	*
// *													*
// *----------------------------------------------------*

	iterator	lower_bound(const key_type &key) {
		return _lower_bound(_head, key);
	}

	const_iterator	lower_bound(const key_type &key) const {
		return _lower_bound(_head, key);
	}

	iterator	_lower_bound(node_pointer node, const key_type &key) const {
		if (_is_lower_bound(node, key))
			return node;
		if (!_key_compare(key, node))
			return _lower_bound(node->right, key);
		return _lower_bound(node->left, key);
	}

	iterator	upper_bound(const key_type &key) {
		return _upper_bound(_head, key);
	}

	const_iterator	upper_bound(const key_type &key) const {
		return _upper_bound(_head, key);
	}

	iterator	_upper_bound(node_pointer node, const key_type &key) const {
		if (_is_upper_bound(node, key))
			return node;
		if (!_key_compare(key, node))
			return _upper_bound(node->right, key);
		return _upper_bound(node->left, key);
	}

private:

	bool	_is_lower_bound(const_iterator current, const key_type &key) const {
		const_iterator	prev(current);

		prev--;
		return (current == begin() || (_key_compare(prev.get_node(), key))) && !_key_compare(current.get_node(), key);
	}

	bool	_is_upper_bound(const_iterator current, const key_type &key) const {
		const_iterator	prev(current);

		prev--;
		return (current == begin() || !_key_compare(key, prev.get_node())) && _key_compare(key, current.get_node());
	}


// *----------------------------------------------------*
// *													*
// *					ROTATE				 		 	*
// *													*
// *----------------------------------------------------*

private:

	void	rotate_left(node_pointer node) {
		node_type	*right_copy = node->right;
		
		right_copy->parent = node->parent;
		_transplant(right_copy, node);
		node->parent = right_copy;
		node->right = right_copy->left;
		if (right_copy->left != _nil)
			right_copy->left->parent = node;
		right_copy->left = node;
	}

	void	rotate_right(node_pointer node) {
		node_type	*left_copy = node->left;
		
		left_copy->parent = node->parent;
		_transplant(left_copy, node);
		node->parent = left_copy;
		node->left = left_copy->right;
		if (left_copy->right != _nil)
			left_copy->right->parent = node;
		left_copy->right = node;
	}
// *----------------------------------------------------*
// *													*
// *			 		ALLOCATOR			 		 	*
// *													*
// *----------------------------------------------------*

public:

		allocator_type	get_allocator() const { return _node_allocator; }
	
// *----------------------------------------------------*
// *													*
// *					MODIFIERS			 		 	*
// *													*
// *----------------------------------------------------*

	size_type	erase(const key_type &key) { return _remove(find(key).get_node()); }

	void		erase(iterator it) { _remove(it.get_node()); }
	
	void		erase(iterator first, iterator last) { 
		while (first != last) {
           	iterator tmp = ++(iterator(first));
            erase(first);
            first = tmp;
        }
	}
	
	void	swap(Rbt &other) {
		ft::swap(_nil, other._nil);
		ft::swap(_end, other._end);
		ft::swap(_rend, other._rend);
		ft::swap(_head, other._head);
		ft::swap(_key_compare, other._key_compare);
		ft::swap(_node_allocator, other._node_allocator);
		ft::swap(_allocator, other._allocator);
		ft::swap(_size, other._size);
	}

	void	clear() { erase(begin(), end()); }
		
// *----------------------------------------------------*
// *													*
// *				COMPARISON OPERATORS	 		 	*
// *													*
// *----------------------------------------------------*


    bool operator==(const Rbt &other) const {
        return size() == other.size() && ft::equal(begin(), end(), other.begin());
    }
	
    bool operator<(const Rbt &other) const {
        return ft::lexicographical_compare(begin(), end(), other.begin(), other.end());
    }
	
    bool operator!=(const Rbt &other) const {
        return !(*this == other);
    }
	
    bool operator>(const Rbt &other) const { return other < *this; }
    
	bool operator<=(const Rbt &other) const {
        return !(*this > other);
    }
	
    bool operator>=(const Rbt &other) const {
        return !(*this < other);
    }

};

}