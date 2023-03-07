/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/07 20:01:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "utility.hpp"

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
	
		node_type	*GetNewNode(pair_type newData, bool is_red) {
			node_type	*node = new node_type(newData, is_red);
			
			node->left = &nil;
			node->right = &nil;
			return node;
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
		}
		
		bool	Search(T1 key) {
			return Search(head, key);
		}

		bool	Search(node_type *node, T1 key) {
			if (node == &nil)
				return false;
			if (node->data.first == key)
				return true;
			if (key < node->data.first)
				return Search(node->left, key);
			return Search(node->right, key);
		}

};

}                    