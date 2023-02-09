/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:11:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/09 18:27:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Allouloucator.hpp"
#include <stdexcept>

template < class T, class Allocator = Allouloucator<T> >

class Vector
{

	public:

	//types

		typedef	typename Allocator::reference			reference;
		typedef	typename Allocator::const_reference		const_reference;
		// typedef											iterator;
		// typedef											const_iterator;
		// typedef											size_type;
		// typedef											difference_type;
		typedef	T										value_type;
		typedef	Allocator								allocator_type;
		typedef	typename Allocator::pointer				pointer;
		typedef	typename Allocator::const_pointer		const_pointer;
		typedef	size_t									size_type;
		// typedef	std::reverse_iterator<iterator>			reverse_iterator;
		// typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;

	//--------- CONSTRUCTOR / COPY / DESTRUCTOR ----------
	
		explicit Vector(const Allocator & = Allocator()) : _data(nullptr), _size(0), _capacity(0) {
			ReAlloc(2);
		}
		explicit Vector(size_type n, const T &value = T(), const Allocator & = Allocator());
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last, const Allocator & = Allocator());
		Vector(const Vector<T, Allocator> &x);
		~Vector(void) {}

		Vector<T, Allocator>	&operator=(const Vector<T, Allocator> &x);
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last);
		void					assign(size_type n, const T &u);
		allocator_type			get_allocator() const { return _allocator; }

	// iterators

	// capacity
	
		void			ReAlloc(size_type newCapacity)	{
			T	*ptr;
			 
			ptr = _allocator.allocate(newCapacity);
			if (newCapacity < _size)
				_size = newCapacity;
			for (size_type i = 0; i < _size; i++)
				ptr[i] = _data[i];
			delete [] _data;
			_data = ptr;
			_capacity = newCapacity;
		}
	
		size_type		size() const { return _size; }
		size_type		max_size() const;
		void			resize(size_type sz, T c = T());
		size_type		capacity() const { return _capacity; }
		bool			empty() const { return (!_size); }
		void			reserve(size_type n); // aggrandit la taille de capacity si capacity est < que n (utiliser l'allocator j'imagine)
	// element access
	
		reference		operator[](size_type n)	{ 
			if (n >= _size)
				throw (std::out_of_range(""));
			return _data[n];
		}

		const_reference	operator[](size_type n) const {
			if (n >= _size)
				throw (std::out_of_range(""));
			return _data[n];
		}

		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;

	// modifiers

		void			push_back(const T &x)	{
			if (_size >= _capacity)
				ReAlloc(_capacity * 2);
			_data[_size] = x;
			_size++;
		}

		void			pop_back();
		// iterator		insert(interator position, const T &x);
		// iterator		insert(interator position, size_type n, const T &x);
		// template <class InputIterator>
		// void			insert(iterator position, InputIterator first, InputIterator last);
		// iterator		erase(iterator position);
		// iterator		erase(iterator first, iterator last);
		void			swap(Vector<T, Allocator> &);
		void			clear();

	private:
		T			*_data;
		size_t		_size;
		size_t		_capacity;
		Allocator	_allocator;
};

template <class T, class Allocator>
bool	operator==(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y);
template <class T, class Allocator>
bool	operator!=(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y);
template <class T, class Allocator>
bool	operator<(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y);
template <class T, class Allocator>
bool	operator>(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y);
template <class T, class Allocator>
bool	operator<=(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y);
template <class T, class Allocator>
bool	operator>=(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y);
template <class T, class Allocator>
bool	swap(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y);
