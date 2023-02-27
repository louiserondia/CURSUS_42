/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:14:46 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/27 15:16:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {

template <class T>

class Iterator
{
	public:

		typedef T								value_type;
		typedef	value_type *					pointer;
		typedef	value_type &					reference;
		typedef	std::ptrdiff_t					difference_type;
		typedef	std::random_access_iterator_tag	iterator_category;

		Iterator(void) : _p(0) {}
		Iterator(pointer p) : _p(p) {}
		Iterator(const Iterator &other) : _p(other._p) {}
		~Iterator(void) {}

		Iterator	&operator=(const Iterator &other) {
			_p = other._p;
			return *this;
		}

		Iterator	operator++(int) {
			Iterator	tmp(*this);
			_p++;
			return tmp;
		}
		
		Iterator	&operator++() {
			_p++;
			return *this;
		}

		Iterator	operator--(int) {
			Iterator	tmp(*this);
			_p--;
			return tmp;
		}
		
		Iterator	&operator--() {
			_p--;
			return *this;
		}
		
		Iterator	&operator+=(difference_type n) { 
			_p += n;
			return *this;
		}
		
		Iterator	&operator-=(difference_type n) { 
			_p -= n;
			return *this;
		}
		
		Iterator			operator+(difference_type n) const{ return _p + n; }
		friend Iterator		operator+(difference_type lhs, const Iterator &rhs) { return rhs + lhs; }
		Iterator			operator-(difference_type n) const { return _p - n; }
		difference_type		operator-(const Iterator &rhs) const { return _p - rhs._p; }
		friend Iterator		operator-(difference_type lhs, const Iterator &rhs) { return rhs - lhs; }
	
		template <class U>
		bool	operator==(const Iterator<U> &other) const { return _p == other.operator->(); }
		
		template <class U>
		bool	operator!=(const Iterator<U> &other) const { return _p != other.operator->(); }
		
		template <class U>
		bool	operator<=(const Iterator<U> &other) const { return _p <= other.operator->(); }
		
		template <class U>
		bool	operator>=(const Iterator<U> &other) const { return _p >= other.operator->(); }
		
		template <class U>
		bool	operator<(const Iterator<U> &other) const { return _p < other.operator->(); }
		
		template <class U>
		bool	operator>(const Iterator<U> &other) const { return _p > other.operator->(); }
		
		reference	operator*() { return *_p; }		
		typename Iterator<const T>::reference	operator*() const { return *_p; }
			
		pointer		operator->() { return _p; }		
		typename Iterator<const T>::pointer		operator->() const { return _p; }		
		
		reference	operator[](difference_type i) { return _p[i]; }
		typename Iterator<const T>::reference	operator[](difference_type i) const { return _p[i]; }
		
		//^ operateur de conversion ^
		operator Iterator< const T >() const {
			return ( Iterator< const T >(_p) );
		}

	private:
		pointer _p;
};

}