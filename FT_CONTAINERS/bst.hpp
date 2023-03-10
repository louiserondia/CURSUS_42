/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/10 18:06:43 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "utility.hpp"
#include "Allouloucator.hpp"

namespace ft {

template  <class T1, class T2>
struct Node {
	
	public :

		typedef ft::pair<T1, T2>	pair_type;
		typedef ft::Node<T1, T2>	node_type;

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

		ft::pair<T1, T2>	data;
		Node				*left;
		Node				*right;
		Node				*parent;
		bool				red;

		void	operator=(const node_type &other) {
			data = other.data;
			left = new Node(other.left);
			right = new Node(other.right);
			red = other.red;
		}

};

template <class T1, class T2>
struct Tree {

	public:
	
		typedef ft::pair<T1, T2>	pair_type;
		typedef ft::Node<T1, T2>	node_type;
	
		node_type	nil;
		node_type	*head;

		Tree() : nil(0), head(&nil) {} 
		
		// constructeur avec iterator		
		
		Tree(const Tree &other) { 
			(void) other;
		}
		
		~Tree() {}
	
	
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
			if (node == head || !node->parent.red) // si parent est noir ou node est la tete
				return;

			if (node->parent == node->parent->parent->right) //~ tante de gauche
			{
				node_type	aunt = node->parent->parent->left;
				
				//~ tante est rouge
				if (aunt.red) {
					aunt.red = false;
					node->parent->parent.red = true;
					node->parent.red = false;
					return insert_fixup(node->parent->parent);
				}
				//~ tante est noire
				if (node == node->parent->left) {
					//* triangle
					//? est-ce que c sur que ca fait la meme chose que si je faisais node = node->p puis rotate_right(node) ?
					rotate_right(node->parent);
					node = node->right;
				}
				//* ligne
				rotate_left(node->parent->parent);
				node->parent.red = false;
				node->parent->left.red = true;
			}
			else { //~ tante de droite
				node_type	aunt = node->parent->parent->right;
				
				//~ tante est rouge
				if (aunt.red) {
					aunt.red = false;
					node->parent->parent.red = true;
					node->parent.red = false;
					return insert_fixup(node->parent->parent);
				}
				//~ tante est noire
				if (node == node->parent->right) {
					//* triangle
					rotate_left(node->parent);
					node = node->left;
				}
				//* ligne
				rotate_right(node->parent->parent);
				node->parent.red = false;
				node->parent->right.red = true;
			}
			head->red = false;
		}

		void	Insert(pair_type newData) {
			Insert(head, newData);
		}

		void	Insert(node_type *node, pair_type newData) {
			if (node == &nil) {
				node = GetNewNode(newData, 0);
				head = node;
				return;
			}
			if (newData < node->data) {
				if (node->left != &nil)
					return Insert(node->left, newData);
				node->left = GetNewNode(newData, 1);
				node->left->parent = node;
			}
			else if (newData > node->data) {
				if (node->right != &nil)
					return Insert(node->right, newData);
				node->right = GetNewNode(newData, 1);
				node->right->parent = node;
			}
			else
				return;
			//~ rééquilibrage
		}
			
			
	// ^----------------------------------------------------^
	// ^													^
	// ^					DELETE				 		 	^
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
			if (node == head) {	//~ la node est la tete
				if (node->left == &nil && node->right == &nil)	//* pas de left ni right
				{
					delete node;
					node = &nil;
					// delete_node(node);
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
			//! comment delete ?????
			// delete node;
			// allocator.destroy(node);
			// node_copy = nil;
			// delete_node(&node_copy);
		}

			
	// ^----------------------------------------------------^
	// ^													^
	// ^					SEARCH				 		 	^
	// ^													^
	// ^----------------------------------------------------^

		bool	Search(T1 key) {
			return Search(head, key);
		}

		bool	Search(node_type *node, T1 key) {
			if (node == &nil) {
				std::cout << "devrait venir ici \n";
				return false;
			}
				std::cout << "NE devrait PAAAAS venir ici \n";
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
		if (right_copy->left != nil)
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
		if (left_copy->right != nil)
			left_copy->right->parent = node;
		left_copy->right = node;
	}

};

}                    