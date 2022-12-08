/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:40:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/06 12:04:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)	{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)	{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const src)	{
	// std::cout << "Int constructor called" << std::endl;
	_fixed = src << Fixed::_bits;
}

Fixed::Fixed(float const src)	{
	// std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(src * ( 1 << Fixed::_bits));
}

Fixed::~Fixed(void)	{
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const	{
	return _fixed;
}

void	Fixed::setRawBits(int const raw)	{
	_fixed = raw;	
}

int		Fixed::toInt(void) const	{
	return _fixed >> Fixed::_bits;
}

float	Fixed::toFloat(void) const	{
	return ((float)_fixed / (1 << Fixed::_bits));
}

Fixed	Fixed::max(Fixed &a, Fixed &b)	{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b)	{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)	{
	if (a < b)
		return (a);
	return (b);
}
Fixed	Fixed::min(const Fixed &a, const Fixed &b)	{
	if (a < b)
		return (a);
	return (b);
}

//	opérateur d'assignation
Fixed	&Fixed::operator=(Fixed const &rhs)	{
	this->_fixed = rhs.getRawBits();
	return (*this);
}

//	opérateur de comparaison
bool	Fixed::operator<(Fixed const &rhs) const	{
	return (_fixed < rhs.getRawBits());
}

bool	Fixed::operator>(Fixed const &rhs) const	{
	return (_fixed > rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const	{
	return (_fixed <= rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const	{
	return (_fixed >= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const	{
	return (_fixed == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const	{
	return (_fixed != rhs.getRawBits());
}

//	opérateur d'arithmétique
Fixed	Fixed::operator+(Fixed const &rhs)	const{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs)	const{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs)	const{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs)	const{
	return (this->toFloat() / rhs.toFloat());
}

//opérateurs d'incrémentation et décrémentation
Fixed	Fixed::operator++(int){
	Fixed	tmp(*this);
	_fixed++;
	return (tmp);
}

Fixed	Fixed::operator++(void)	{
	_fixed++;
	return (*this);
}

Fixed	Fixed::operator--(int){
	Fixed	tmp(*this);
	_fixed--;
	return (tmp);
}

Fixed	Fixed::operator--(void)	{
	_fixed--;
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &rhs)	{
	o << rhs.toFloat();
	return (o);
}
