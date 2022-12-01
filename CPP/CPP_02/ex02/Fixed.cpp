/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:40:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/01 13:18:12 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixed(0)	{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)	{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const src)	{
	std::cout << "Int constructor called" << std::endl;
	_fixed = src << Fixed::_bits;
}

Fixed::Fixed(float const src)	{
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(src * ( 1 << Fixed::_bits));
}

Fixed::~Fixed(void)	{
	std::cout << "Destructor called" << std::endl;
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

//	opérateur d'assignation
Fixed	&Fixed::operator=(Fixed const &rhs)	{
	std::cout << "Copy assignment operator called" << std::endl;
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

//	opérateur de comparaison
Fixed	Fixed::operator+(Fixed const &rhs)	const{
	return (_fixed + rhs.getRawBits());
}

Fixed	Fixed::operator-(Fixed const &rhs)	const{
	return (_fixed - rhs.getRawBits());
}

Fixed	Fixed::operator*(Fixed const &rhs)	const{
	return (_fixed * rhs.getRawBits());
}

Fixed	Fixed::operator/(Fixed const &rhs)	const{
	return (_fixed / rhs.getRawBits());
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
