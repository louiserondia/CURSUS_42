/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:11:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/04/07 17:43:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Allouloucator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include "utility.hpp"
#include <stdexcept>
#include <string>
#include <algorithm>

// ^--------------------------------------------------------^
// ^	 __   __   ___     ___    _____    ___     ___   	^	
// ^	 \ \ / /  | __|   / __|  |_   _|  / _ \   | _ \  	^
// ^	  \ V /   | _|   | (__     | |   | (_) |  |   /  	^
// ^	  _\_/_   |___|   \___|   _|_|_   \___/   |_|_\  	^
// ^	_| """"|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 	^
// ^	"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 	^
// ^--------------------------------------------------------^

namespace ft {

template < class T, class Allocator = Allouloucator<T> >

class vector {

	// ^----------------------------------------------------^
	// ^													^
	// ^					ITERATOR			 		 	^
	// ^													^
	// ^----------------------------------------------------^

	template <class U>
	class Iterator {

		public:

			typedef U								value_type;
			typedef	value_type						*pointer;
			typedef	value_type 						&reference;
			typedef	std::ptrdiff_t					difference_type;
			typedef	std::random_access_iterator_tag	iterator_category;

		private:
		
			pointer _p;

		public:
		
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
			template <class V>
			difference_type		operator-(const Iterator<V> &rhs) const { return _p - rhs.operator->(); }
			friend Iterator		operator-(difference_type lhs, const Iterator &rhs) { return rhs - lhs; }
		
			template <class V>
			bool	operator==(const Iterator<V> &other) const { return _p == other.operator->(); }
			
			template <class V>
			bool	operator!=(const Iterator<V> &other) const { return _p != other.operator->(); }
			
			template <class V>
			bool	operator<=(const Iterator<V> &other) const { return _p <= other.operator->(); }
			
			template <class V>
			bool	operator>=(const Iterator<V> &other) const { return _p >= other.operator->(); }
			
			template <class V>
			bool	operator<(const Iterator<V> &other) const { return _p < other.operator->(); }
			
			template <class V>
			bool	operator>(const Iterator<V> &other) const { return _p > other.operator->(); }
			
			reference	operator*() const { return *_p; }		
				
			pointer		operator->() const  { return _p; }		
			
			reference	operator[](difference_type i) const { return _p[i]; }
			
			// operateur de conversion
			operator Iterator< const U >() const {
				return ( Iterator< const U >(_p) );
			}
	};

	// ^----------------------------------------------------^
	// ^													^
	// ^					TYPEDEFS			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
	public:

		typedef	T											value_type;
		typedef	Allocator									allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	std::size_t									size_type;
		typedef	std::ptrdiff_t								difference_type;
		typedef	Iterator<value_type>						iterator;
		typedef	Iterator<const value_type>					const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		MEMBERS							^
	// ^													^
	// ^----------------------------------------------------^

	protected:

		T			*_data;
		size_t		_size;
		size_t		_capacity;
		Allocator	_allocator;

	// ^----------------------------------------------------^
	// ^													^
	// ^			 CONSTRUCTOR / DESTRUCTOR			 	^
	// ^													^
	// ^----------------------------------------------------^
	
	public:

		explicit vector(const Allocator &alloc = Allocator()):
		_data(0),
		_size(0),
		_capacity(0),
		_allocator(alloc) {
			reserve(2);
		}
		
		explicit vector(size_type n, const T &value = T(), const Allocator &alloc = Allocator()) :
		_data(0),
		_size(0),
		_capacity(0),
		_allocator(alloc) {
			reserve(n);
			assign(n, value);
		}
		
		template <class InputIterator>
		vector(InputIterator first, 
				InputIterator last, 
				const Allocator &alloc = Allocator(),
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type * = 0) : 
		_data(0),
		_size(0),
		_capacity(0),
		_allocator(alloc) {
			reserve(std::distance(first, last));
			assign(first, last);
		}
		
		vector(const vector &x) :
		_data(0),
		_size(0),
		_capacity(0),
		_allocator(x._allocator) {
			reserve(2);
			reserve(x.size());
			assign(x.begin(), x.end());
		}

		~vector(void) {
			clear();
			_allocator.deallocate(_data, _capacity);
		}

		vector	&operator=(const vector &x)	{
			assign(x.begin(), x.end());
			_size = x._size;
			_capacity = x._capacity;
			_allocator = x._allocator;
			return *this;
		}

		template <class InputIterator>
		void	assign(InputIterator first,
						InputIterator last, 
						typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type * = 0) {
			clear();
			insert(begin(), first, last);
		}

		void	assign(size_type n, const T &u)	{
			clear();
			insert(begin(), n, u);
		}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		ITERATORS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		iterator				begin() { return iterator(_data); }
		const_iterator			begin() const { return const_iterator(_data); }
		iterator				end() { return iterator(_data + _size); }
		const_iterator			end() const { return const_iterator(_data + _size); }
		reverse_iterator		rbegin() { return reverse_iterator(_data + _size); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(_data + _size); }
		reverse_iterator		rend() { return reverse_iterator(_data); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		 ALLOCATOR					 	^
	// ^													^
	// ^----------------------------------------------------^
		
		allocator_type	get_allocator() const { return _allocator; }
		const_reverse_iterator	rend() const { return const_reverse_iterator(_data); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		CAPACITY			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
		size_type		size() const { return _size; }
		size_type		max_size() const { return _allocator.max_size(); }
		size_type		capacity() const { return _capacity; }
		bool			empty() const { return (!_size); }

		void			resize(size_type sz, T c = T())	{
			if (sz > max_size())
				throw(std::length_error(""));
			if (_size > sz)
				erase(begin() + sz, end());
			if (_size < sz)
				insert(end(), sz - _size, c);
		}
		
		void			 reserve(size_type n) {
			T	*ptr;
			if (n > max_size())
				throw (std::length_error(""));
			if (_capacity < n)	{
				ptr = _allocator.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(ptr + i, _data[i]);
				for(size_type i = 0; i < _size; i++)
					_allocator.destroy(_data + i);
				_allocator.deallocate(_data, _capacity);
				_data = ptr;
				_capacity = n;
			}
		}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	ELEMENT ACCESS			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
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

		reference		at(size_type n)	{
			if (n > _size)
				throw(std::out_of_range(""));
			return _data[n];
		}
		
		const_reference	at(size_type n) const {
			if (n > _size)
				throw(std::out_of_range(""));
			return _data[n];
		}
		
		reference		front() { return _data[0]; }
	
		const_reference	front() const { return _data[0]; }
		
		reference	back() {
			return _data[size() - 1];
		}
		
		const_reference	back() const {
			return _data[size() - 1];
		}

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		MODIFIERS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		void			push_back(const T &x)	{
			if (_size >= _capacity)
				reserve(_capacity * 2);
			_allocator.construct(_data + _size, x);
			_size++;
		}

		void			pop_back()	{
			if (_size)	{
				_allocator.destroy(_data + _size - 1);
				_size--;
			}
		}
		
		iterator		insert(iterator position, const T &x)	{
			difference_type	index_pos = std::distance(begin(), position);
			
			insert(position, 1, x);
			return begin() + index_pos;
		}

	/*	0.	allouer la taille nécessaire & récupérer la bonne valeur de position
		1.	ajouter les elements de l'ancien vecteur dans la mémoire non-initialisée
		2.	ajouter les elements du nouveau vecteur dans la mémoire non-initialisée
		3.	copier les élements restants de l'ancien vecteur dans la mémoire déjà initialisée
		4.	copier les éléments restants du nouveau vecteur dans la mémoire déjà initialisée	*/

		void	insert(iterator position, size_type n, const T &x) {
			typedef difference_type diff_t;

			diff_t	old_uninit = std::min(n, (size_type)(end() - position));
			diff_t	new_uninit = std::max((diff_t)0, (diff_t)(n - (end() - position)));
			diff_t	index_pos = std::distance(begin(), position);
			diff_t	old_rest = std::max((diff_t)0, (diff_t)_size - (diff_t)n - index_pos);
			diff_t	max = std::min((diff_t)_size, index_pos + (diff_t)n);

			if (_capacity < _size + n)
				reserve(std::max(_size + n, _size * 2));
			position = begin() + index_pos;
			for (diff_t i = 0; i < old_uninit; i++)
				_allocator.construct(_data + _size + new_uninit + i, _data[index_pos + old_rest + i]);
			for (diff_t j = 0; j < new_uninit; j++)
				_allocator.construct(_data + _size + j, x);
			if (old_rest)
				std::copy_backward(position, end() - n, end());
			for (diff_t i = index_pos; i != max; i++)
				_data[i] = x;
			_size += n;
		}

		template <class InputIterator>
		void	insert(iterator position, InputIterator first, InputIterator last, 
						typename enable_if< !is_integral< InputIterator >::value, InputIterator >::type * = 0) {
			typedef difference_type diff_t;

			diff_t	n = std::distance(first, last);
			diff_t	old_uninit = std::min(n, end() - position);
			diff_t	new_uninit = std::max((diff_t)0, n - (end() - position));
			diff_t	index_pos = position - begin();
			diff_t	old_rest = (diff_t)_size - n - index_pos;
			diff_t	max = std::min((diff_t)_size, index_pos + n);

			if (_capacity < _size + n)
				reserve(std::max(_size + n, _size * 2));
			position = begin() + index_pos;
			for (diff_t i = 0; i < old_uninit; i++)
				_allocator.construct(_data + _size + new_uninit + i, _data[index_pos + old_rest + i]);
			std::advance(last, - new_uninit);
			for (diff_t j = 0; j < new_uninit; j++, last++)
				_allocator.construct(_data + _size + j, *last);
			if (old_rest > 0)
				std::copy_backward(position, end() - n, end());
			for (diff_t k = index_pos; k < max; k++, first++) {
				_data[k] = *first;
			}
			_size += n;
		}
		
		iterator		erase(iterator position) {
			erase(position, position + 1);
			return position;
		}
		
		iterator		erase(iterator first, iterator last) {
			std::copy(last, end(), first);
			for (iterator it = first + (end() - last); it != end(); it++) {
				_allocator.destroy(it.operator->());
			}
			_size -= last - first;
			return first;
		}

		void	swap(vector<T, Allocator> &other) {
			ft::swap(_data, other._data);
			ft::swap(_size, other._size);
			ft::swap(_capacity, other._capacity);
			ft::swap(_allocator, other._allocator);
		}
		
		void			clear()	{
			while(_size)	{
				_data[_size - 1].~T();
				_size--;
			}
		}
};


// ^----------------------------------------------------^
// ^													^
// ^			 	COMPARAISON OVERLOADS				^
// ^													^
// ^----------------------------------------------------^

template <class T, class Allocator>
bool	operator==(const vector<T, Allocator> & x, const vector<T, Allocator> &y) {
	return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <class T, class Allocator>
bool	operator!=(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	return !(x == y);
}

template <class T, class Allocator>
bool	operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class T, class Allocator>
bool	operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	return y < x;
}

template <class T, class Allocator>
bool	operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	return !(y < x);
}

template <class T, class Allocator>
bool	operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	return !(x < y);
}

template <class T, class Allocator>
void	swap(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	x.swap(y);
}


}