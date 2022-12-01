/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:40:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/30 16:16:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:

	int					_fixed;
	static int const	_bits = 8;

public:
	Fixed(void);
	Fixed(Fixed const &src);
	~Fixed(void);

	Fixed	&operator=(Fixed const &rhs);
	
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
