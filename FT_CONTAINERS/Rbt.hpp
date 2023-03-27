/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/27 16:12:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "utility.hpp"
#include "Allouloucator.hpp"

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

	struct Node {

	public :

		typedef typename Allocator::template rebind<Node>::other	allocator_type; //? pas tout a fait sure de comprendre le ::template et les 3 valeurs
		typedef typename allocator_type::pointer					pointer;

		Node(bool is_red) :
			data(),
			left(NULL),
			right(NULL),
			parent(NULL),
			red(is_red),
			is_nil(false) {}

		Node(const value_type &pair, bool is_red) : 
			data(pair), 
			left(NULL), 
			right(NULL), 
			parent(NULL), 
			red(is_red),
			is_nil(false) {}

		Node(const Node &other) :
			data(other.data), 
			left(other.left), 
			right(other.right), 
			parent(other.parent), 
			red(other.red),
			is_nil(false) {}

		static void destroy(pointer node, allocator_type &allocator) {
			allocator.destroy(node);
			allocator.deallocate(node, 1);
		}

		value_type	data;
		Node		*left;
		Node		*right;
		Node		*parent;
		bool		red;
		bool		is_nil;

		void	operator=(const Node &other) {
			data = other.data;
			left = new Node(other.left);
			right = new Node(other.right);
			red = other.red;
		}
	};



// ~----------------------------------------------------~
// ~----------------------------------------------------~
// ~													~
// ~													~
// ~				RED BLACK TREE					 	~
// ~													~
// ~													~
// ~----------------------------------------------------~
// ~----------------------------------------------------~


public:

	typedef Node							node_type;
	typedef typename Node::allocator_type	node_allocator_type;
	typedef typename Node::pointer			node_pointer;

// ^----------------------------------------------------^
// ^													^
// ^					MEMBERS						 	^
// ^													^
// ^----------------------------------------------------^

	node_type			nil;
	node_type			*head;
	node_pointer		_begin;
	node_pointer		_rbegin;
	node_pointer		_end;
	node_pointer		_rend;
	size_type			_size;
	node_allocator_type	_allocator;

// ^----------------------------------------------------^
// ^													^
// ^				 CON/DESTRUCTORS				 	^
// ^													^
// ^----------------------------------------------------^

	Rbt() : nil(0), head(&nil) {
		nil.is_nil = true;
	} 
	
	// constructeur avec iterator		
	
	Rbt(const Rbt &other) { 
		(void) other;
	}
	
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
		// jusqu'à trouver une node qui est enfant de gauche et alors on se positione sur son parent (si il n'est pas nil)

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
			return _node == other.get_node;
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

	iterator				begin() { return ++iterator(_end); }
	const_reverse_iterator	rend() const {}


// ^----------------------------------------------------^
// ^													^
// ^					  INSERT					 	^
// ^													^
// ^----------------------------------------------------^

	value_type	insert(const value_type newData) {
		return *_insert(head, newData);
	}

	iterator	insert(iterator hint, const value_type newData) {
		if (is_upper_bound(hint, newData))
			return _insert(hint.get_node(), newData);
		return _insert(head, newData);
	}

private:

	node_type	*_add_new_node(value_type newData, bool is_red) {
		node_type	*node = new node_type(newData, is_red);
		
		node->left = &nil;
		node->right = &nil;
		return node;
	}

	void	_insert_fixup(node_pointer node) {
		if (node == head || !node->parent->red) // si parent est noir ou node est la tete
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
		head->red = false;
	}
	
	iterator	_insert(node_pointer node, const value_type newData) { // :000
		if (node == &nil && node == head) {
			node = _add_new_node(newData, 0);
			head = node;
			return node; //~ return la pair qu'on a ajoutée, à VERIFIER
		}
		if (node == &nil && node->parent != &nil) {
			node = _add_new_node(newData, 0);
			return node; //~ return la pair qu'on a ajoutée
		}
		if (newData.first < node->data.first) {
			if (node->left != &nil)
				return _insert(node->left, newData);
			node->left = _add_new_node(newData, 1);
			node->left->parent = node;
			_insert_fixup(node->left);
		}
		else if (newData.first > node->data.first) {
			if (node->right != &nil)
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
		node = &nil;
	}
		
	node_type	*get_biggest_node(node_pointer node) {
		node_type	*copy = node;

		while (copy != &nil && copy->right != &nil) {
			copy = copy->right;
		}
		return copy;
	}

	node_type	*get_smallest_node(node_pointer node) {
		node_type	*copy = node;

		while (copy != &nil && copy->left != &nil) {
			copy = copy->left;
		}
		return copy;
	}

	//^ a utiliser dans rotate
	void	transplant(node_pointer from, node_pointer to) {
		from->parent = to->parent;
		if (to == head)
			head = from;
		else if (to ==  to->parent->left)
			to->parent->left = from;
		else
			to->parent->right = from;
	}
	
private:

	void	_remove_fixup(node_pointer x) {
		if (x == head || x->red) {
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
	
	void	_remove(node_pointer node) {
		node_pointer	z = node;
		node_pointer	y = z;
		node_pointer	x;
		bool			y_origin_color = y->red;
		
		if (node == &nil)
			return;
		if (z->left == &nil)
			x = z->right;
		else if (z->right == &nil)
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
	}

		
// ^----------------------------------------------------^
// ^													^
// ^					HEIGHT				 		 	^
// ^													^
// ^----------------------------------------------------^

public:

	size_type	height(Node *node) {
		if (node == &nil) {
			return 0;
		}
		return 1 + std::max(height (node->left), height(node->right));
	}

// ^----------------------------------------------------^
// ^													^
// ^			FIND + COUNT + LOWERBOUND	 		 	^
// ^													^
// ^----------------------------------------------------^

	iterator	find(const key_type key) {
		return find(head, key);
	}

	iterator	find(node_pointer node, const key_type key) {
		if (node == &nil)
			return _end;
		if (node->data.first == key)
			return node;
		if (key < node->data.first)
			return find(node->left, key);
		return find(node->right, key);
	}

	const_iterator	find(const key_type key) const {
		return find(head, key);
	}

	const_iterator	find(node_pointer node, const key_type key) const {
		if (node == &nil)
			return _end;
		if (node->data.first == key)
			return node;
		if (key < node->data.first)
			return find(node->left, key);
		return find(node->right, key);
	}

	size_type	count(const key_type key) const {
		return *find(head, key) == _end ? false : true;
	}

	iterator	lower_bound(const key_type key) {
		return lower_bound(head, key, nil);
	}

	iterator	lower_bound(node_pointer node, const key_type key, node_pointer prev) {
		if (node == &nil)
			return prev == nil ? _end : prev;
		if (node->data.first <= key)
			return lower_bound(node->right, key, prev);
		prev = node;
		return lower_bound(node->left, key, prev);
	}

	const_iterator	lower_bound(const key_type key) const {
		return lower_bound(head, key);
	}

	const_iterator	lower_bound(node_pointer node, const key_type key, node_pointer prev) const {
		if (node == &nil)
			return prev == nil ? _end : prev;
		if (node->data.first <= key)
			return lower_bound(node->right, key, prev);
		prev = node;
		return lower_bound(node->left, key, prev);
	}

	iterator	upper_bound(const key_type key) {
		return _upper_bound(head, key, nil);
	}

	iterator	_upper_bound(node_pointer node, const key_type key, node_pointer prev) {
		if (node == &nil)
			return prev == nil ? _end : prev;
		if (node->data.first > key)
			return upper_bound(node->right, key, prev);
		prev = node;
		return upper_bound(node->left, key, prev);
	}

	const_iterator	upper_bound(const key_type key) const {
		return upper_bound(head, key);
	}

	const_iterator	upper_bound(node_pointer node, const key_type key, node_pointer prev) const {
		if (node == &nil)
			return prev == nil ? _end : prev;
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
			head = right_copy;
		else if (node == node->parent->right)
			node->parent->right = right_copy;
		else
			node->parent->left = right_copy;
		node->parent = right_copy;
		node->right = right_copy->left;
		if (right_copy->left != &nil)
			right_copy->left->parent = node;
		right_copy->left = node;
	}

	void	rotate_right(node_pointer node) {
		node_type	*left_copy = node->left;
		
		left_copy->parent = node->parent;
		if (node->parent == NULL)
			head = left_copy;
		else if (node == node->parent->left)
			node->parent->left = left_copy;
		else
			node->parent->right = left_copy;
		node->parent = left_copy;
		node->left = left_copy->right;
		if (left_copy->right != &nil)
			left_copy->right->parent = node;
		left_copy->right = node;
	}
};

}                    