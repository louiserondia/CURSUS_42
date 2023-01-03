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
		Array(void);
		Array(Array const &copy);
		Array(unsigned int n);
		~Array(void);

        Array	        &operator=(Array const &rhs);
        T   	        &operator[](unsigned int n);

		T const         getelem(int n) const;
        unsigned int    size() const;

	private :
		unsigned int _size;
		T       	*_elem;
};

#endif


