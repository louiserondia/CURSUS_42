/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:40:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/02 15:38:03 by lrondia          ###   ########.fr       */
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
	Fixed(int const src);
	Fixed(float const src);
	Fixed(Fixed const &src);
	~Fixed(void);

	//opérateur d'assignation
	Fixed	&operator=(Fixed const &rhs);
	
	//opérateurs de comparaison
	bool	operator<(Fixed const &rhs) const;
	bool	operator>(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator==(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	
	//opérateurs d'arithmétique
	Fixed	operator+(Fixed const &rhs) const;
	Fixed	operator-(Fixed const &rhs) const;
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;

	//opérateurs d'incrémentation et décrémentation
	Fixed	operator++(int);
	Fixed	operator++(void);
	Fixed	operator--(int);
	Fixed	operator--(void);

	//fonctions membres
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat(void) const;
	int				toInt(void) const;
	static Fixed	max(Fixed &a, Fixed &b);
	static Fixed	max(const Fixed &a, const Fixed &b);
	static Fixed	min(Fixed &a, Fixed &b);
	static Fixed	min(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs);

#endif
