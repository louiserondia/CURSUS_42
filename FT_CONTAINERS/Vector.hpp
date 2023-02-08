/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:11:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/08 18:16:05 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Allouloucator.hpp"

template < class T, class Allocator = Allouloucator<T> >

class Vector
{

	public:

	//types
		typedef	typename Allocator::reference			reference;
		typedef	typename Allocator::const_reference		const_reference;

		//iterators
		// typedef											iterator;
		// typedef											const_iterator;
		// typedef											size_type;
		// typedef											difference_type;

		typedef	T										value_type;
		typedef	Allocator								allocator_type;
		typedef	typename Allocator::pointer				pointer;
		typedef	typename Allocator::const_pointer		const_pointer;
		// typedef	std::reverse_iterator<iterator>			reverse_iterator;
		// typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;

	
		Vector(void) : _size(0), _capacity(0) {}
		~Vector(void) {}


	private:
		size_t	_size;
		size_t	_capacity;
};
