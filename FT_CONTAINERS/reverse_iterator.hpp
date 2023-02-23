/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 23:00:48 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/23 23:00:48 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Vector.hpp"
#include "Allouloucator.hpp"

namespace ft {

	template <class Iterator>
	class reverse_iterator :
		public iterator<	typename std::iterator_traits<Iterator>::iterator_category,
							typename std::iterator_traits<Iterator>::value_type,
							typename std::iterator_traits<Iterator>::difference_type,
							typename std::iterator_traits<Iterator>::poiter,
							typename std::iterator_traits<Iterator>::reference>

	{
		protected:
			Iterator current;
		
		public:

			typedef Iterator													iterator_type;
			typedef typename std::iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename std::iterator_traits<Iterator>::pointer			pointer;
			typedef typename std::iterator_traits<Iterator>::reference			reference;


			reverse_iterator();
			explicit reverse_iterator(Iterator x) : current(x) {}
			template <class U>
			reverse_iterator(const reverse_iterator<U> &u) : current(u.current) {}
			
			reverse_iterator &operator=(const reverse_iterator<U> &other) {
				current = other.current;
				return *this;
			}

			Iterator	base() const { return current; } //explicit
			reference	operator*() const {
				Iterator tmp = current;
				return *--tmp;
			}
			pointer		operator->() const { return &(operator *()); }

			reverse_iterator	&operator++() {
				--current;
				return *this;
			}

			reverse_iterator	operator++(int n) {
				reverse_iterator tmp = *this;
				--current;
				return tmp;
			}
			
			reverse_iterator	&operator--() {
				++current;
				return *this;
			}
			
			reverse_iterator	operator--(int n) {
				reverse_iterator tmp = *this;
				++current;
				return tmp;
			}

			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(current - n); }
			
			reverse_iterator	&operator+=(difference_type n) {
				current -= n;
				return *this;
			}
			
			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(current + n); }
			
			reverse_iterator	&operator-=(difference_type n) {
				current += n;
				return *this;
			}
			
			reference			operator[](difference_type n) const { return current[ - n - 1 ]; } //??? ou utiliser operator+ avec n ca return une copie a cet endroit

			~reverse_iterator();

	};

	template <class Iterator>
	bool	operator==(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.current == y.current;
	}

	template <class Iterator>
	bool	operator!=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.current != y.current;
	}

	template <class Iterator>
	bool	operator<(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.current > y.current;
	}

	template <class Iterator>
	bool	operator>(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.current < y.current;
	}

	template <class Iterator>
	bool	operator<=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.current >= y.current;
	}

	template <class Iterator>
	bool	operator>=(const reverse_iterator<Iterator> &x, const reverse_iterator<Iterator> &y) {
		return x.current <= y.current;
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	operator-(
			const reverse_iterator<Iterator> &x,
			const reverse_iterator<Iterator> &y) {
		return x.current - y.current;
	}

	template <class Iterator>
	bool	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &x) {
		return reverse_iterator<Iterator> n(x.current - n); //? puis-je ?
	}

}
