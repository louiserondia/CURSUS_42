/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:11:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/15 17:39:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Allouloucator.hpp"
#include "Iterator.hpp"
#include <stdexcept>


struct V3	{
	float x;
	float y;
	float z;

	V3() : x(0), y(0), z(0) { /*std::cout << "Default constructor\n";*/ }
	V3(float x, float y, float z) : x(x), y(y), z(z) { /*std::cout << "Constructor\n";*/ }
	V3(const V3 &copy) : x(copy.x), y(copy.y), z(copy.z) { /*std::cout << "Copy constructor\n";*/ }
	~V3() { /*std::cout << "Destroy\n";*/ }

	void	printV3(){
		std::cout << "x " << x << "	y " << y << "	z " << z << "\n";
	}
};

// ^--------------------------------------------------------^
// ^	 __   __   ___     ___    _____    ___     ___   	^	
// ^	 \ \ / /  | __|   / __|  |_   _|  / _ \   | _ \  	^
// ^	  \ V /   | _|   | (__     | |   | (_) |  |   /  	^
// ^	  _\_/_   |___|   \___|   _|_|_   \___/   |_|_\  	^
// ^	_| """"|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 	^
// ^	"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 	^
// ^--------------------------------------------------------^
	

// template < class T, class Allocator = Allouloucator<T> >
template < class T, class Allocator = std::allocator<T> >

class Vector
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
		typedef	std::reverse_iterator<iterator>			reverse_iterator;
		typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef	std::size_t								size_type; // ? difference si j'ecris juste size_t ?
		typedef	std::ptrdiff_t							difference_type;


	// ^----------------------------------------------------^
	// ^													^
	// ^		 CONSTRUCTOR / DESTRUCTOR / ASSIGN		 	^
	// ^													^
	// ^----------------------------------------------------^
	
		explicit Vector(const Allocator &alloc = Allocator()) : _data(0), _size(0), _capacity(0), _allocator(alloc) {
			ReAlloc(2);
		}
		
		explicit Vector(size_type n, const T &value = T(), const Allocator &alloc = Allocator()) : _data(0), _size(0), _capacity(0), _allocator(alloc) {
			ReAlloc(2);
			assign(n, value);
		}
		
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last, const Allocator &alloc = Allocator()) : _data(0), _size(0), _capacity(0), _allocator(alloc) {
			ReAlloc(2);
			for (InputIterator it = first; it != last; it++)
				push_back(*it);
		}
		
		Vector(const Vector<T, Allocator> &x);
		~Vector(void) {
			clear();
			_allocator.deallocate(_data, _capacity);
		}

		Vector<T, Allocator>	&operator=(const Vector<T, Allocator> &x);
		allocator_type			get_allocator() const { return _allocator; }
		
		template <class InputIterator>
		void					assign(InputIterator first, InputIterator last) {  // ? verifier et utiliser insert
			clear();
			for (InputIterator it = first; it != last; it++)	{
				push_back(*it);
			}
		}
		
		void					assign(size_type n, const T &u)	{
			clear();
			while (_size < n)
				push_back(u);
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
		reverse_iterator		rbegin() { return reverse_iterator(_data + _size - 1); }
		const_reverse_iterator	rbegin() const { return const_reverse_iterator(_data + _size - 1); }
		reverse_iterator		rend() { return iterator(_data - 1); }
		const_reverse_iterator	rend() const { return const_iterator(_data - 1); }

	// ^----------------------------------------------------^
	// ^													^
	// ^			 		CAPACITY			 		 	^
	// ^													^
	// ^----------------------------------------------------^
	
	
		size_type		size() const { return _size; }
		size_type		max_size() const { return std::numeric_limits<size_type>::max() / sizeof(size_type); }
		size_type		capacity() const { return _capacity; }
		bool			empty() const { return (!_size); }
		
		void			ReAlloc(size_type newCapacity)	{
			T	*ptr;
			
			if (newCapacity > max_size())
				throw(std::length_error(""));
			ptr = _allocator.allocate(newCapacity);
			if (newCapacity < _size)
				_size = newCapacity;
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(ptr + i, _data[i]);
			for(size_type i = 0; i < _size; i++)
				_allocator.destroy(_data + i);
			_allocator.deallocate(_data, _capacity);
			_data = ptr;
			_capacity = newCapacity;
		}
		
		void			resize(size_type sz, T c = T())	{ // ? peut-etre a refaire avec insert ??
			if (sz > max_size())
				throw(std::length_error(""));
			while (_size > sz)
				pop_back();
			while (_size < sz)
				push_back(c);
		}
		
		void			 reserve(size_type n) {
			if (n > max_size())
				throw (std::length_error(""));
			if (_capacity < n)	{
				ReAlloc(n);
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
			if (_size > 0)
				return _data[size() - 1];
			return _data[0];
		}
		
		const_reference	back() const { // ? refaire avec un iterator non ? c-a-d renvoyer begin() ou end() directement
			if (_size > 0)
				return _data[size() - 1];
			return _data[0];
		}


	// ^----------------------------------------------------^
	// ^													^
	// ^			 		MODIFIERS			 		 	^
	// ^													^
	// ^----------------------------------------------------^

		void			push_back(const T &x)	{
			if (_size >= _capacity)
				ReAlloc(_capacity * 2);
			_allocator.construct(_data + _size, x);
			_size++;
		}

		void			pop_back()	{
			if (_size)	{
				_allocator.destroy(_data + _size - 1);
				_size--;
			}
		}
		
		iterator		insert(iterator position, const T &x);
		iterator		insert(iterator position, size_type n, const T &x);
		template <class InputIterator>
		void			insert(iterator position, InputIterator first, InputIterator last);
		iterator		erase(iterator position);
		iterator		erase(iterator first, iterator last);
		void			swap(Vector<T, Allocator> &);
		
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
bool	operator==(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y) {
	if (x.size() != y.size())
		return false;
	for (size_t i = 0; i < x.size(); i++)	{
		if (x.at(i) != y.at(i))
			return false;
	}
	return true;
}

template <class T, class Allocator>
bool	operator!=(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y) {
	
}

template <class T, class Allocator>
bool	operator<(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y) {
	
}

template <class T, class Allocator>
bool	operator>(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y) {
	
}

template <class T, class Allocator>
bool	operator<=(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y) {
	
}

template <class T, class Allocator>
bool	operator>=(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y) {
	
}

template <class T, class Allocator>
bool	swap(const Vector<T, Allocator> &x, const Vector<T, Allocator> &y) {
	
}
