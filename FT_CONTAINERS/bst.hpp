/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/03/01 17:52:03 by lrondia          ###   ########.fr       */
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

		//? creer un constructeur qui cree un arbre vide etc ?

		ft::pair<T1, T2>	data;
		BstNode				*left;
		BstNode				*right;

		bst_type	GetNewNode(pair_type data) {
			bst_type	*newNode = new bst_type();
			newNode->data = data;
			newNode->left = NULL;
			newNode->right = NULL;
			return newNode;
		}

		bst_type	*Insert(pair_type newData) {
			if (!*this)
				*this = GetNewNode(newData);
			else if (newData.first <= data.first)
				left = Insert(left, newData);
			else if (newData.first > data.first)
				right = Insert(right, newData);
		}

		bool	Search(pair_type newData) {
			if (!*this)
				return false;
			if (data == newData)
				return true;
			else if (newData.first <= data.first)
				return Search(left, newData);
			else if (newData.first > data.first)
				return Search(right, newData);
		}

		void	operator=(const bst_type &other) {
			left = other.left;
			right = other.right;
			data = other.data;
		}
};


}