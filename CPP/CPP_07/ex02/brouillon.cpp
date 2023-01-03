/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:07:55 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/03 17:40:11 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0), _elem (0) {}
		
template <typename T>
Array<T>::Array(Array const &copy) : _size(copy._size)    {
    _elem = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _elem[i] = copy._elem[i];
    }
}

template <typename T>
Array<T>::Array(unsigned int n) {
    _size = n;
	_elem = new T[_size];
}

template <typename T>
Array<T>::~Array(void)    {
   if (_elem)
	   delete [] _elem;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &rhs)    {
    if (_elem)
        delete [] _elem;
    _size = rhs._size;
    _elem = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _elem[i] = rhs._elem[i];
    }
}

template <typename T>
T	&Array<T>::operator[](unsigned int n) {
    if (_size == 0 || n >= _size)
        throw std::out_of_range("index was out of range.");
    return _elem[n];
}

template <typename T>
T const   Array<T>::getelem(int n) const {
    return _elem[n];
}

template <typename T>
unsigned int Array<T>::size() const    {
    return _size;
}
