/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:51:52 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/17 15:38:06 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <functional>
# include <string_view>
# include <vector>
# include <cmath>


class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &copy);
		~Span(void);

		Span			&operator=(Span const &src);

		void				addNumber(int number);
		void				addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		std::vector<int>	getTab() const;
		unsigned int		shortestSpan() const;
		unsigned int		longestSpan() const;
		
		class SpanTooShortException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
	
		

	private:
		Span(void);

		unsigned int	 	N;
		std::vector<int>	_tab;
};

std::ostream	&operator<<(std::ostream &o, Span const &rhs);

#endif
