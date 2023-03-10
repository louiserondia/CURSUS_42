/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Allouloucator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:15:02 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/08 14:39:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft {

template <class T>
class Allouloucator
{
	public:

		typedef size_t		size_type;
		typedef	ptrdiff_t	difference_type;
		typedef	T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef	const T&	const_reference;
		typedef	T			value_type;

		template <class U>
		struct rebind {
			typedef Allouloucator<U>	other;
		};

		Allouloucator() throw() : _n_alloc(0), _n_construct(0) {}
		Allouloucator(const Allouloucator &copy) throw() : _n_alloc(copy._n_alloc), _n_construct(copy._n_construct) {};
		template <typename U>
		Allouloucator(const Allouloucator<U> &) throw();
		~Allouloucator() throw() {}

		pointer			adress(reference x) const	{ return &x; }
		const_pointer	adress(const_reference x) const	{ return &x; }

		pointer			allocate(size_type n, const_pointer = 0)	{
			if (n)
				_n_alloc++;
			return reinterpret_cast<pointer>(::operator new(n * sizeof(value_type)));
		}

		void			deallocate(pointer p, size_type n)	{
			if (n)
				_n_alloc--;
			::operator delete(p);
		}

		size_type		max_size() const throw()	{
			return std::numeric_limits<size_type>::max() / sizeof(size_type);
		}

		void			construct(pointer p, const value_type &val)	{
			_n_construct++;
			new ((void *) p) value_type(val);
		}
	
		void			destroy(pointer p)	{
			if (_n_construct)
				_n_construct--;
			p->~value_type();
		}

		size_type		get_n_alloc()	{ return _n_alloc; }
		size_type		get_n_construct()	{ return _n_construct; }

	private:
		size_type _n_alloc;
		size_type _n_construct;

};

template <class T1, class T2>
bool		operator==(const Allouloucator<T1> &A1, const Allouloucator<T2> &A2) throw() { 
	return (A1->_n_alloc == A2._n_alloc && A1->_n_constuct == A2._n_constuct);
}
template <class T1, class T2>
bool		operator!=(const Allouloucator<T1> &A1, const Allouloucator<T2> &A2) throw() {
	return (A1._n_alloc != A2._n_alloc || A1._n_constuct != A2._n_constuct);
}

}