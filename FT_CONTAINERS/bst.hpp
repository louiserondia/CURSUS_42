/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/06 16:40:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "utility.hpp"

namespace ft {

template  <class T1, class T2>
struct BstNode {
	
	public :

		typedef ft::pair<T1, T2>	pair_type;
		typedef ft::BstNode<T1, T2>	bst_type;

		bstNode() : data(NULL), left(NULL), right(NULL) {}
		bstNode(const pair_type &pair) : data(NULL), left(NULL), right(NULL) {}
		bstNode(const BstNode &other) : data(other.data), left(other.left), right(other.right) {}
		//? creer un constructeur qui cree un arbre vide etc ?

		ft::pair<T1, T2>	data;
		BstNode				*left;
		BstNode				*right;

		void	operator=(const bst_type &other) {
			left = other.left;
			right = other.right;
			data = other.data;
		}
};

template <class T1, class T2>
struct Tree {

	public:
	
		BstNode	*head;

		Tree() : head(BstNode()) {}
		Tree(const BstNode &x) : head(BstNode(x)) {}
		Tree(const Tree &other) : head(other) {}
		~Tree() {}

		void	operator=(const Tree &other) {
			head = ohter.head;
		}

		bst_type	GetNewNode(bst_type tree, pair_type newData) {
			tree->data = newData;
			tree->left = NULL;
			tree->right = NULL;
			return newNode;
		}

		void	Insert(Tree *tree, pair_type newData) {
			if (!tree->head->data)
				GetNewNode(&tree->head->data, newData);
			else if (newData.first <= data->first)
				Insert(&tree->head->left, newData);
			else if (newData.first > head->data->first)
				Insert(&tree->head->right, newData);
		}

		bool	Search(Tree tree, pair_type newData) {
			if (!head)
				return false;
			if (data == newData)
				return true;
			else if (newData.first <= data.first)
				return Search(left, newData);
			else if (newData.first > data.first)
				return Search(right, newData);
		}

};

}