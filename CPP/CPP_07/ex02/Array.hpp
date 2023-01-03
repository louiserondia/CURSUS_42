/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:35:11 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/03 17:40:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <iostream>
# include <stdexcept>

template <typename T>
class	Array	{

	public :
		Array(void) : _elem (0), _size(0) {}
		
		Array(Array const &copy) : _size(copy._size)    {
    		_elem = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elem[i] = copy._elem[i];
		    }
		}
		
		Array(unsigned int n) {
		    _size = n;
    		_elem = new T[_size];
		}
	
		~Array(void)    {
		   if (_elem)
    		   delete [] _elem;
		}
		
        Array	&operator=(Array const &rhs)    {
            if (_elem)
                delete [] _elem;
            _size = rhs._size;
            _elem = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _elem[i] = rhs._elem[i];
            }
        }

        T	&operator[](unsigned int n) {
            if (n < 0 || n >= _size)
                throw std::out_of_range("Index was out of range.");
            return this->_elem[n];
        }

		T const   getelem(int n) const {
    	    return _elem[n];
		}
        
        int size() const    {
            return _size;
        }
        

	private :
		unsigned int	_size;
		T				*_elem;
};

#endif
