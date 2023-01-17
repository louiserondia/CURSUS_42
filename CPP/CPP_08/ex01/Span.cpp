/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:52:38 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/17 12:44:46 by lrondia          ###   ########.fr       */
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
		if (_tab.size() >= N)
			throw std::out_of_range("Span is already full of numbers");
		_tab.push_back(number);
		std::sort(_tab.begin(), _tab.end());
	}
	catch (std::out_of_range &o) {
		std::cout << o.what() << ": " << *this << std::endl;
	}
}

std::vector<int>	Span::getTab() const	{
	return _tab;
}

unsigned int	Span::shortestSpan(void)	{
	int	min = -1;
	int comp;
	std::vector<int>::iterator i;

	if (!_tab.size() || _tab.size() == 1)
		throw Span::SpanTooShortException();
	for (i = _tab.begin(); i != _tab.end() - 1; i++)	{
		comp = *i - *(i + 1);
		comp = abs(comp);
		if (min == -1 || comp < min)
			min = comp;
	}
	return min;
}

unsigned int	Span::longestSpan(void)	{
	int	max = 0;
	int comp;
	std::vector<int>::iterator i;

	if (!_tab.size() || _tab.size() == 1)
		throw Span::SpanTooShortException();
	for (i = _tab.begin(); i != _tab.end() - 1; i++)	{
		comp = *i - *(i + 1);
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
	std::vector<int>::iterator i;
	
	for (i = _tab.begin(); i != _tab.end() - 1; i++)
		o << rhs.getTab()[i] << " ";
	std::cout << std::endl;
	return (o);
}
        