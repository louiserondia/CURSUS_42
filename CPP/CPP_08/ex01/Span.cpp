/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:52:38 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/12 18:19:12 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)	{
}

Span::Span(unsigned int n) : N(n)	{
}

Span::Span(Span const &copy) : N(copy.N)	{
}

Span	&Span::operator=(Span const &src)	{
	N = src.N;
	return *this;
}

Span::~Span(void)	{
}

void	Span::addNumber(int number)	{
	try {
		if (_amount_of_nb >= N)
			throw std::out_of_range("Span is already full of numbers");
		_tab.push_back(number);
		_amount_of_nb++;
		std::sort(_tab.begin(), _tab.end());
	}
	catch (std::out_of_range &o) {
		std::cout << o.what() << ": " << *this << std::endl;
	}
}

std::vector<int>	Span::getTab() const	{
	return _tab;
}

unsigned int	Span::getAmountOfNb() const	{
	return _amount_of_nb;
}

unsigned int	Span::shortestSpan(void)	{
	int	min = -1;
	int comp;

	if (!_amount_of_nb || _amount_of_nb == 1)
		throw Span::SpanTooShortException();
	for (unsigned int i = 0; i < _amount_of_nb - 1; i++)	{
		comp = _tab[i] - _tab[i + 1];
		comp = abs(comp);
		if (min == -1 || comp < min)
			min = comp;
	}
	return min;
}

unsigned int	Span::longestSpan(void)	{
	int	max = 0;
	int comp;

	if (!_amount_of_nb || _amount_of_nb == 1)
		throw Span::SpanTooShortException();
	for (unsigned int i = 0; i < _amount_of_nb - 1; i++)	{
		comp = _tab[i] - _tab[i + 1];
		comp = abs(comp);
		if (comp > max)
			max = comp;
	}
	return max;
}

const char	*Span::SpanTooShortException::what() const throw()	{
	return ("Span is too small.");
}

std::ostream	&operator<<(std::ostream &o, Span const &rhs)	{
	for (unsigned int i = 0; i < rhs.getAmountOfNb(); i++)
		o << rhs.getTab()[i] << " ";
	std::cout << std::endl;
	return (o);
}
