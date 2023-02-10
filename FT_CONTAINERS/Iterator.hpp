/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/10 18:53:37 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// template <
// 	class Category,
// 	class T,
// 	class Distance = ptrdiff_t,
// 	class Pointer = T*,
// 	class Reference = T&
// 	>

template <class T>

class Iterator
{
	public:

		typedef T								value_type;
		typedef	value_type *					pointer;
		typedef	value_type &					reference;
		typedef	std::ptrdiff_t					difference_type;
		typedef	std::random_access_iterator_tag	iterator_category;

		// typedef T			value_type;
		// typedef	Distance	difference_type;
		// typedef	Pointer		pointer;
		// typedef	Reference	reference;
		// typedef	Category	iterator_category;


		Iterator(void) : _p(0) {}
		Iterator(pointer p) : _p(p) {}
		Iterator(const Iterator &other) : _p(other._p) {}
		~Iterator(void) {}

		Iterator	&operator=(const Iterator &other) {
			_p(other._p);
			return *this;
		}

		Iterator	begin()	{ return Iterator(_p); }
		Iterator	end()	{ return Iterator(_p); } //? comment ajouter _size ?

		template <class U>
		bool	operator==(const Iterator<U> &other) const { return _p == other._p; }
		
		template <class U>
		bool	operator!=(const Iterator<U> &other) const { return _p != other._p; }
		
		template <class U>
		bool	operator<=(const Iterator<U> &other) const { return _p <= other._p; }
		
		template <class U>
		bool	operator>=(const Iterator<U> &other) const { return _p >= other._p; }
		
		template <class U>
		bool	operator<(const Iterator<U> &other) const { return _p < other._p; }
		
		template <class U>
		bool	operator>(const Iterator<U> &other) const { return _p > other._p; }
		
		reference	operator*() { return *_p; }		
		typename Iterator<const T>::reference	operator*() const { return *_p; }
			
		pointer		operator->() { return _p; }		
		typename Iterator<const T>::pointer		operator->() const { return _p; }		
		
		reference	operator[](difference_type i) { return _p[i]; }
		typename Iterator<const T>::reference	operator[](difference_type i) const { return _p[i]; }
		
		//??? operator Iterator< const U >() const {
		//? 	return ( Iterator< const U >( _p ) );
		//? }

	private:
		pointer _p;
};