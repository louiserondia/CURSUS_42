/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:11:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/24 14:53:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Allouloucator.hpp"
#include "Iterator.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include "utils.hpp"
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

class vector
{

	public:


	// ^----------------------------------------------------^
	// ^													^
	// ^					TYPEDEFS			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
		typedef	T										value_type;
		typedef	Allocator								allocator_type;
		typedef	typename Allocator::reference			reference;
		typedef	typename Allocator::const_reference		const_reference;
		typedef	typename Allocator::pointer				pointer;
		typedef	typename Allocator::const_pointer		const_pointer;
		typedef	Iterator<value_type>					iterator;
		typedef	Iterator<const value_type>				const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef	std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;


	// ^----------------------------------------------------^
	// ^													^
	// ^		 CONSTRUCTOR / DESTRUCTOR / ASSIGN		 	^
	// ^													^
	// ^----------------------------------------------------^
	
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
			reserve(2);
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
			for (InputIterator it = first; it != last; it++)
				push_back(*it);
		}
		
		vector(const vector<T, Allocator> &x) :
		_data(0),
		_size(0),
		_capacity(0),
		_allocator(x._allocator) {
			assign(x.begin(), x.end());
		}

		~vector(void) {
			clear();
			_allocator.deallocate(_data, _capacity);
		}

		vector<T, Allocator>	&operator=(const vector<T, Allocator> &x)	{
			assign(x.begin(), x.end());
			_size = x._size;
			_capacity = x._capacity;
			_allocator = x._allocator;
			return *this;
		}

		allocator_type	get_allocator() const { return _allocator; }
		
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
		iterator				end() { return iterator(_data + _size); } //? est-ce qu'il envoie pas un trop tôt ?
		const_iterator			end() const { return const_iterator(_data + _size); }
		reverse_iterator		rbegin() { return reverse_iterator(_data + _size); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(_data + _size); }
		reverse_iterator		rend() { return reverse_iterator(_data); }
		const_reverse_iterator	rend() const { return const_reverse_iterator(_data); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		CAPACITY			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
	
		size_type		size() const { return _size; }
		size_type		max_size() const { return std::numeric_limits<size_type>::max() / sizeof(size_type); }
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
			if (n < _size)
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
			for (diff_t j = 0; j < new_uninit; j++)
				_allocator.construct(_data + _size + j, *(last - new_uninit + j));
			if (old_rest > 0)
				std::copy_backward(position, end() - n, end());
			for (diff_t k = index_pos; k != max; k++)
				_data[k] = *(first + k - index_pos);
			_size += n;
		}
		
		iterator		erase(iterator position) {
			bool	is_end = false;
			bool	is_last = false;

			if (position == end() - 1) { is_last = true; }
			if (position == end()) { is_end = true; }
	
			if (is_end)
				return end();
			_allocator.destroy(position.operator->());
			if (_size)
				_size--;
			if (!is_last)
				std::copy(position + 1, end() + 1, position);
			return position + 1;
		}
		
		iterator		erase(iterator first, iterator last) {
			bool		is_end = false;
			bool		is_last = false;
			
			if (last == end() - 1) { is_last = true; }
			if (last == end()) { is_end = true; }
	
			for (iterator it = first; it != last; it++) {
				_allocator.destroy(it.operator->());
				if (_size)
					_size--;
			}
			if (!is_end) {
				std::copy(last, end() + 1, first);
				return first;
			}
			return end(); 
			//^return le dernier et si last est + loin que end, alors return end
			//? le mien ne segfault pas quand je return end alors que si j'essaie de print le vrai dans le main ca segfault
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

	// ^----------------------------------------------------^
	// ^													^
	// ^			 	PRIVATE INSTANCES					^
	// ^													^
	// ^----------------------------------------------------^

	private:
		T			*_data;
		size_t		_size;
		size_t		_capacity;
		Allocator	_allocator;
};


// ^----------------------------------------------------^
// ^													^
// ^			 	COMPARAISON OVERLOADS				^
// ^													^
// ^----------------------------------------------------^

template <class T, class Allocator>
bool	operator==(const vector<T, Allocator> & x, const vector<T, Allocator> &y) {
	return x._size == y._size && ft::equal(x.begin(), x.end(), y.begin());
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
	return !(x < y);
}

template <class T, class Allocator>
bool	operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	return !(y < x);
}

template <class T, class Allocator>
void	swap(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
	x.swap(y);
}


}