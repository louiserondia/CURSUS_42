/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/24 13:40:49 by lrondia          ###   ########.fr       */
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

struct Node {
	
	public :

		typedef ft::pair<Key, Value>								pair_type;
		typedef typename Allocator::template rebind<Node>::other	allocator_type; //? pas tout a fait sure de comprendre le ::template et les 3 valeurs
		typedef typename allocator_type::pointer					pointer;

		Node(bool is_red) :
			data(),
			left(NULL),
			right(NULL),
			parent(NULL),
			red(is_red) {}
	
		Node(const pair_type &pair, bool is_red) : 
			data(pair), 
			left(NULL), 
			right(NULL), 
			parent(NULL), 
			red(is_red) {}
	
		Node(const Node &other) :
			data(other.data), 
			left(other.left), 
			right(other.right), 
			parent(other.parent), 
			red(other.red) {}

 		static void destroy(pointer node, allocator_type &allocator) {
			allocator.destroy(node);
			allocator.deallocate(node, 1);
		}

		ft::pair<Key, Value>	data;
		Node					*left;
		Node					*right;
		Node					*parent;
		bool					red;

		void	operator=(const Node &other) {
			data = other.data;
			left = new Node(other.left);
			right = new Node(other.right);
			red = other.red;
		}

};


//~~~~~~~~~~~~~~~~~~~
//~		 TREE		~
//~~~~~~~~~~~~~~~~~~~

	public:
	
		typedef ft::pair<Key, Value>			pair_type;
		typedef Node							node_type;
		typedef typename Node::allocator_type	node_allocator_type;
		typedef typename Node::pointer			node_pointer;

		//* Members

		node_allocator_type	_allocator;
		node_type			nil;
		node_type			*head;

		Rbt() : nil(0), head(&nil) {} 
		
		// constructeur avec iterator		
		
		Rbt(const Rbt &other) { 
			(void) other;
		}
		
		~Rbt() {}
	
	
	// ^----------------------------------------------------^
	// ^													^
	// ^					ITERATOR					 	^
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

			Iterator() : _node(&nil) {}
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
				if (_node->right != &nil) {
					_node = _node->right;
					while (_node->left != &nil)
						_node = _node->left;
				}
				else {
					if (_node == _node->parent->left)
					_node = _node->parent;
					else {
						node_pointer	tmp = _node;
						while (tmp->parent != &nil && tmp != tmp->parent->left)
							tmp = tmp->parent;
						if (tmp->parent != &nil)
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
				if (_node->left != &nil) {
					_node = _node->left;
					while (_node->right != &nil)
						_node = _node->right;
				}
				else {
					if (_node == _node->parent->right)
					_node = _node->parent;
					else {
						node_pointer	tmp = _node;
						while (tmp->parent != &nil && tmp != tmp->parent->right)
							tmp = tmp->parent;
						if (tmp->parent != &nil)
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

		private:
			node_pointer _node;
	}

	// ^----------------------------------------------------^
	// ^													^
	// ^					  ACCESS					 	^
	// ^													^
	// ^----------------------------------------------------^
	
		node_type	*first() { return head; }

	// ^----------------------------------------------------^
	// ^													^
	// ^					  INSERT					 	^
	// ^													^
	// ^----------------------------------------------------^
	
		node_type	*GetNewNode(pair_type newData, bool is_red) {
			node_type	*node = new node_type(newData, is_red);
			
			node->left = &nil;
			node->right = &nil;
			return node;
		}

		void	insert_fixup(node_type *node) {
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
					return insert_fixup(node->parent->parent);
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
					return insert_fixup(node->parent->parent);
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

		void	Insert(pair_type newData) {
			Insert(head, newData);
		}

		void	Insert(node_type *node, pair_type newData) { // :000
			if (node == &nil && node == head) {
				node = GetNewNode(newData, 0);
				head = node;
				return;
			}
			if (node == &nil && node->parent != &nil) {
				node = GetNewNode(newData, 0);
				return;
			}
			if (newData < node->data) {
				if (node->left != &nil)
					return Insert(node->left, newData);
				node->left = GetNewNode(newData, 1);
				node->left->parent = node;
				insert_fixup(node->left);
			}
			else if (newData > node->data) {
				if (node->right != &nil)
					return Insert(node->right, newData);
				node->right = GetNewNode(newData, 1);
				node->right->parent = node;
				insert_fixup(node->right);
			}
			else
				return;
		}
			
			
	// ^----------------------------------------------------^
	// ^													^
	// ^					REMOVE				 		 	^
	// ^													^
	// ^----------------------------------------------------^
			
		void	delete_node(node_type *node) {
			delete node;
			node = &nil;
		}
			
		node_type	*get_biggest_node(node_type *node) {
			node_type	*copy = node;

			while (copy != &nil && copy->right != &nil) {
				copy = copy->right;
			}
			return copy;
		}

		void	set_new_node(node_type *node, node_type *new_node) {
			if (new_node == new_node->parent->right)
				new_node->parent->right = &nil;
			else
				new_node->parent->left = &nil;
			new_node->parent = &nil;
			new_node->left = node->left;
			new_node->right = node->right;
			new_node->red = node->red;
		}
		
		void	set_new_node(node_type *child_of_parent_of_node, node_type *node, node_type *new_node) {
			child_of_parent_of_node = new_node;
			if (new_node == new_node->parent->right)
				new_node->parent->right = &nil;
			else
				new_node->parent->left = &nil;
			new_node->parent = node->parent;
			new_node->left = node->left;
			new_node->right = node->right;
			new_node->red = node->red;
		}
		
		void	remove(node_type *node) {
			// node_type	node_copy = node;
			
			if (node == &nil)
				return ;
			if (node == head) {									//~ la node est la tete
				if (node->left == &nil && node->right == &nil)	//* pas de left ni right
				{
					Node::destroy(node, _allocator);
					if (node == &nil)
						std::cout << "ouiiii : \n";
					else
						std::cout << "nooooon : \n";
					return;
					
				}
				else if (node->left == &nil)					//* pas de left
					node = node->right;
				else if (node->right == &nil)					//* pas de right
					node = node->left;
				else											//* aller chercher l'enfant le plus grand parmi les plus petits
					set_new_node(node, get_biggest_node(node->left));
			}
			else if (node == node->parent->right) {	//~ node est a droite de son parent
				if (node->left == &nil && node->right == &nil)
					node->parent->right = &nil;
				else if (node->left == &nil) {
					node->parent->right = node->right;
					node = node->right;
				}
				else if (node->right == &nil) {
					node->parent->right = node->left;
					node = node->left;
				}
				else
					set_new_node(node->parent->right, node, get_biggest_node(node->left));
			}
			else {									//~ node est a gauche de son parent
				if (node->left == &nil && node->right == &nil)
					node->parent->left = &nil;
				else if (node->left == &nil) {
					node->parent->left = node->right;
					node = node->right;
				}
				else if (node->right == &nil) {
					node->parent->left = node->left;
					node = node->left;
				}
				else
					set_new_node(node->parent->left, node, get_biggest_node(node->left));
			}
			// /!\ delete
		}

			
	// ^----------------------------------------------------^
	// ^													^
	// ^					HEIGHT				 		 	^
	// ^													^
	// ^----------------------------------------------------^

		

		size_type	height(Node *node) {
    		if (node == &nil) {
    		    return 0;
    		}
    		return 1 + std::max(height (node->left), height(node->right));
		}

	// ^----------------------------------------------------^
	// ^													^
	// ^					SEARCH				 		 	^
	// ^													^
	// ^----------------------------------------------------^

		bool	Search(Key key) {
			return Search(head, key);
		}

		bool	Search(node_type *node, Key key) {
			if (node == &nil)
				return false;
			if (node->data.first == key)
				return true;
			if (key < node->data.first)
				return Search(node->left, key);
			return Search(node->right, key);
		}

			
	// ^----------------------------------------------------^
	// ^													^
	// ^					ROTATE				 		 	^
	// ^													^
	// ^----------------------------------------------------^

	void	rotate_left(node_type *node) {
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

	void	rotate_right(node_type *node) {
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