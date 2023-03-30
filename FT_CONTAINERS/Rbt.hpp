/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/30 12:43:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "utility.hpp"
#include "Allouloucator.hpp"
#include "reverse_iterator.hpp"

namespace ft {

template <	typename Key,
			typename Value,
			typename Comp = std::less<Key>,
			typename Allocator = ft::Allouloucator<ft::pair<const Key, Value> > >

class	Rbt {

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

private: 

	struct _Node {

	public :

		typedef typename Allocator::template rebind<_Node>::other	node_allocator_type; //? pas tout a fait sure de comprendre le ::template et les 3 valeurs
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

		node_pointer	clone(node_allocator_type &alloc) {
			node_pointer	node = alloc.allocate(1);
			alloc.construct(node, *this);
			return node;
		}

		static void destroy(pointer node, node_allocator_type &alloc) {
			alloc.destroy(node);
			alloc.deallocate(node, 1);
		}

		value_type	data;
		_Node		*left;
		_Node		*right;
		_Node		*parent;
		bool		red;
		bool		is_nil;

		void	operator=(const _Node &other) {
			data = other.data;
			left = new _Node(other.left);
			right = new _Node(other.right);
			red = other.red;
		}
	};


public:

	typedef _Node								node_type;
	typedef typename _Node::node_allocator_type	node_allocator_type;
	typedef typename _Node::node_pointer		node_pointer;


// ~----------------------------------------------------~
// ~----------------------------------------------------~
// ~													~
// ~													~
// ~				RED BLACK TREE					 	~
// ~													~
// ~													~
// ~----------------------------------------------------~
// ~----------------------------------------------------~


// ^----------------------------------------------------^
// ^													^
// ^				EXTENDED KEY COMPARE	 		 	^
// ^													^
// ^----------------------------------------------------^

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
            return _comp( a, b->data->first );
        }
        bool	operator()( const node_pointer &a, const key_type &b ) const {
            if (a == _end)
				return false;
            if (a == _rend)
				return true;
            return _comp( a->data->first, b );
        }
		
        const key_compare	&key_comp() const { return _comp; }

};

// ^----------------------------------------------------^
// ^													^
// ^					MEMBERS						 	^
// ^													^
// ^----------------------------------------------------^

private:

	node_type				_nil;
	node_allocator_type		_node_allocator;
	allocator_type			_allocator;
	node_pointer			_end;
	node_pointer			_rend;
	node_pointer			_head;
	extended_key_compare	_key_compare;
	size_type				_size;

// ^----------------------------------------------------^
// ^													^
// ^				 CON/DESTRUCTORS				 	^
// ^													^
// ^----------------------------------------------------^

public:

	Rbt(const key_compare &comp = key_compare()) :
		_nil(), 
		_node_allocator(node_allocator_type()), 
		_allocator(allocator_type()), 
		_end(node_type(false, &_nil, &_nil).clone(_node_allocator)),
		_rend(node_type(false, &_nil, &_nil).clone(_node_allocator)),
		_head(_end),
		_key_compare(extended_key_compare(_end, _rend, comp)),
		_size(0) {
		_nil.is_nil = true;
	} 
	
	// constructeur avec iterator		
	
	Rbt(const Rbt &other) :
		_nil(), 
		_node_allocator(other._node_allocator), 
		_allocator(other._allocator), 
		_end(node_type(false, &_nil, &_nil).clone(_node_allocator)),
		_rend(node_type(false, &_nil, &_nil).clone(_node_allocator)),
		_head(_end),
		_key_compare(extended_key_compare(_end, _rend, other._key_compare.key_comp())),
		_size(0) {
		insert(other.begin(), other.end());
	}
	//? pourquoi valentin met _root->left a rend ?
	
	~Rbt() {}


// ^----------------------------------------------------^
// ^													^
// ^				 RBT ITERATOR					 	^
// ^													^
// ^----------------------------------------------------^


	template <typename T>
	class Iterator {

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
			_node = other.node;
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
				if (_node == _node->parent->left)
				_node = _node->parent;
				else {
					node_pointer	tmp = _node;
					while (tmp->parent->is_nil == false && tmp != tmp->parent->left)
						tmp = tmp->parent;
					if (tmp->parent->is_nil == false)
						_node = tmp->parent;
				}
			}		
			return *this;
		}
			
		Iterator	operator++(int) {
			Iterator	tmp(*this);
			
			++*this;
			return tmp;
		}

		Iterator	&operator--() {
			if (_node->left->is_nil == false) {
				_node = _node->left;
				while (_node->right->is_nil == false)
					_node = _node->right;
			}
			else {
				if (_node == _node->parent->right)
				_node = _node->parent;
				else {
					node_pointer	tmp = _node;
					while (tmp->parent->is_nil == false && tmp != tmp->parent->right)
						tmp = tmp->parent;
					if (tmp->parent->is_nil == false)
						_node = tmp->parent;
				}
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


	typedef	Iterator<value_type>					iterator;
	typedef	Iterator<const value_type>				const_iterator;
	typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	iterator				begin() { return ++iterator(_rend); }
	const_iterator			begin() const { return ++iterator(_rend); }
	iterator				end() { return _end; }
	const_iterator			end() const { return _end; }
	reverse_iterator		rbegin() { return end(); }
	const_reverse_iterator	rbegin() const { return end(); }
	reverse_iterator		rend() { return begin(); }
	const_reverse_iterator	rend() const { return begin(); }


// ^----------------------------------------------------^
// ^													^
// ^					  INSERT					 	^
// ^													^
// ^----------------------------------------------------^

	value_type	insert(const value_type newData) {
		return *_insert(_head, newData);
	}

	iterator	insert(iterator hint, const value_type newData) {
		if (is_upper_bound(hint, newData))
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
		
		node->left = &_nil;
		node->right = &_nil;
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
	
	iterator	_insert(node_pointer node, const value_type newData) { // :000
		if (node == &_nil && node == _head) {
			node = _add_new_node(newData, 0);
			_head = node;
			return node; //~ return la pair qu'on a ajoutée, à VERIFIER
		}
		if (node == &_nil && node->parent != &_nil) {
			node = _add_new_node(newData, 0);
			return node; //~ return la pair qu'on a ajoutée
		}
		if (newData.first < node->data.first) {
			if (node->left != &_nil)
				return _insert(node->left, newData);
			node->left = _add_new_node(newData, 1);
			node->left->parent = node;
			_insert_fixup(node->left);
		}
		else if (newData.first > node->data.first) {
			if (node->right != &_nil)
				return _insert(node->right, newData);
			node->right = _add_new_node(newData, 1);
			node->right->parent = node;
			_insert_fixup(node->right);
		}
		return node; //~ renvoyer la pair égale à celle qu'on a essayer d'ajouter.
	}


// ^----------------------------------------------------^
// ^													^
// ^					REMOVE				 		 	^
// ^													^
// ^----------------------------------------------------^

public:

	void	delete_node(node_pointer node) {
		delete node;
		node = &_nil;
	}
		
	node_type	*get_biggest_node(node_pointer node) {
		node_type	*copy = node;

		while (copy != &_nil && copy->right != &_nil) {
			copy = copy->right;
		}
		return copy;
	}

	node_type	*get_smallest_node(node_pointer node) {
		node_type	*copy = node;

		while (copy != &_nil && copy->left != &_nil) {
			copy = copy->left;
		}
		return copy;
	}

	//^ a utiliser dans rotate
	void	transplant(node_pointer from, node_pointer to) {
		from->parent = to->parent;
		if (to == _head)
			_head = from;
		else if (to ==  to->parent->left)
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
				return remove_fixup(x);
			}
			// soeur est noire
			if (!sista->left->red && !sista->right->red) { // les enfants de la soeur sont noirs
				sista->red = true;
				return remove_fixup(x->parent);
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
				return remove_fixup(x);
			}
			// soeur est noire
			if (!sista->right->red && !sista->left->red) { // enfants de la soeur sont noirs
				sista->red = true;
				return remove_fixup(x->parent);
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
		
		if (node == &_nil)
			return 1;
		if (z->left == &_nil)
			x = z->right;
		else if (z->right == &_nil)
			x = z->left;
		else {
			y = get_smallest_node(z->right);
			x = y->right;
			transplant(x, y);
			transplant(y, z);
			y->left = z->left;
			z->left->parent = y;
			y->right = z->right;
			z->right->parent = y;
			y_origin_color = y->red;
			y->red = z->red;
		}
		if (!y_origin_color) //y est noir
			remove_fixup(x);
		return 1;
	}

		
// ^----------------------------------------------------^
// ^													^
// ^					HEIGHT				 		 	^
// ^													^
// ^----------------------------------------------------^

public:

	size_type	height() { return _height(_head); }

private:

	size_type	_height(_Node *node) {
		if (node == &_nil) {
			return 0;
		}
		return 1 + std::max(_height (node->left), _height(node->right));
	}

// ^----------------------------------------------------^
// ^													^
// ^			FIND + COUNT + LOWERBOUND	 		 	^
// ^													^
// ^----------------------------------------------------^

public:

	iterator	find(const key_type key) {
		return find(_head, key);
	}

	iterator	find(node_pointer node, const key_type key) {
		if (node == &_nil)
			return _end;
		if (node->data.first == key)
			return node;
		if (key < node->data.first)
			return find(node->left, key);
		return find(node->right, key);
	}

	const_iterator	find(const key_type key) const {
		return find(_head, key);
	}

	const_iterator	find(node_pointer node, const key_type key) const {
		if (node == &_nil)
			return _end;
		if (node->data.first == key)
			return node;
		if (key < node->data.first)
			return find(node->left, key);
		return find(node->right, key);
	}

	size_type	count(const key_type key) const {
		return *find(_head, key) == _end ? false : true;
	}

	iterator	lower_bound(const key_type key) {
		return lower_bound(_head, key, _nil);
	}

	iterator	lower_bound(node_pointer node, const key_type key, node_pointer prev) {
		if (node == &_nil)
			return prev == _nil ? _end : prev;
		if (node->data.first <= key)
			return lower_bound(node->right, key, prev);
		prev = node;
		return lower_bound(node->left, key, prev);
	}

	const_iterator	lower_bound(const key_type key) const {
		return lower_bound(_head, key);
	}

	const_iterator	lower_bound(node_pointer node, const key_type key, node_pointer prev) const {
		if (node == &_nil)
			return prev == _nil ? _end : prev;
		if (node->data.first <= key)
			return lower_bound(node->right, key, prev);
		prev = node;
		return lower_bound(node->left, key, prev);
	}

	iterator	upper_bound(const key_type key) {
		return _upper_bound(_head, key, _nil);
	}

	iterator	_upper_bound(node_pointer node, const key_type key, node_pointer prev) {
		if (node == &_nil)
			return prev == _nil ? _end : prev;
		if (node->data.first > key)
			return upper_bound(node->right, key, prev);
		prev = node;
		return upper_bound(node->left, key, prev);
	}

	const_iterator	upper_bound(const key_type key) const {
		return upper_bound(_head, key);
	}

	const_iterator	upper_bound(node_pointer node, const key_type key, node_pointer prev) const {
		if (node == &_nil)
			return prev == _nil ? _end : prev;
		if (node->data.first > key)
			return upper_bound(node->right, key, prev);
		prev = node;
		return upper_bound(node->left, key, prev);
	}

private:

	bool	_is_lower_bound(const_iterator current, const key_type &key) const {
		const_iterator	prev(current);

		prev--;
		return (current == begin() || (prev->first > key && current->first < key));
	}

	bool	_is_upper_bound(const_iterator current, const key_type &key) const {
		const_iterator	prev(current);

		prev--;
		return (current == begin() || (prev->first < key && current->first > key));
	}
	
//~ je pourrais surcharger operateurs de comp et utiliser dedans keycompare ?


// ^----------------------------------------------------^
// ^													^
// ^					ROTATE				 		 	^
// ^													^
// ^----------------------------------------------------^

public:

	void	rotate_left(node_pointer node) {
		node_type	*right_copy = node->right;
		
		right_copy->parent = node->parent;
		if (node->parent == NULL)
			_head = right_copy;
		else if (node == node->parent->right)
			node->parent->right = right_copy;
		else
			node->parent->left = right_copy;
		node->parent = right_copy;
		node->right = right_copy->left;
		if (right_copy->left != &_nil)
			right_copy->left->parent = node;
		right_copy->left = node;
	}

	void	rotate_right(node_pointer node) {
		node_type	*left_copy = node->left;
		
		left_copy->parent = node->parent;
		if (node->parent == NULL)
			_head = left_copy;
		else if (node == node->parent->left)
			node->parent->left = left_copy;
		else
			node->parent->right = left_copy;
		node->parent = left_copy;
		node->left = left_copy->right;
		if (left_copy->right != &_nil)
			left_copy->right->parent = node;
		left_copy->right = node;
	}

// ^----------------------------------------------------^
// ^													^
// ^					MODIFIERS			 		 	^
// ^													^
// ^----------------------------------------------------^

	size_type	erase(const key_type &key) { return _remove(find(key).get_node()); }

	void		erase(iterator it) { _remove(it.get_node()); }
	
	void		erase(iterator first, iterator last) { 
		for (size_type i = 0; i < last - first; i++) {
			iterator	it(first + i);
			_remove(it.get_node());
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

};

}                    