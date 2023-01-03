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

template <typename T>
class	Array	{
	public :
		Array(void);
		~Array(void);
	private :
		T	*_array;
}

#endif
