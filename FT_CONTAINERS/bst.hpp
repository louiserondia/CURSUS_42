/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/06 19:33:08 by lrondia          ###   ########.fr       */
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

		BstNode() : data(), head(this), left(NULL), right(NULL) {}
		BstNode(const pair_type &pair) : data(pair), head(this), left(NULL), right(NULL) {}
		BstNode(const BstNode &other) : data(other.data), head(this), left(other.left), right(other.right) {}
		//? creer un constructeur qui cree un arbre vide etc ?

		ft::pair<T1, T2>	data;
		BstNode				*head;
		BstNode				*left;
		BstNode				*right;

		void	operator=(const bst_type &other) {
			data = other.data;
			left = new BstNode(other.left);
			right = new BstNode(other.right);
		}

		void	GetNewNode(bst_type *bst, pair_type newData) {
			bst->data = newData;
			bst->left = new BstNode();
			bst->right = new BstNode();
		}

		void	Insert(bst_type *bst, pair_type newData) {
			if (!bst->data)
				GetNewNode(bst, newData);
			else if (newData < bst->data)
				Insert(left, newData);
			else
				Insert(right, newData);
		}

		bool	Search(bst_type *bst, pair_type newData) {
			if (!bst->data)
				return false;
			if (bst->data == newData)
				return true;
			else if (newData < bst->data)
				return Search(left, newData);
			else
				return Search(right, newData);
		}

};

}