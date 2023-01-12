/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/12 18:29:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	Span span(6);

	srand(time(NULL));
	span.addNumber(0);
	std::cout << span << std::endl;
	try	{
		std::cout << span.shortestSpan() << std::endl;
	}
	catch(const Span::SpanTooShortException &e)	{
		std::cerr << e.what() << '\n';
	}
	
	span.addNumber(10);
	span.addNumber(1000);
	span.addNumber(-1000);
	span.addNumber(-1);
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	
	std::cout << " | TEST ON BIG SPAN | \n";

	Span big_span(10000);
	for (int i = 0; i < 10000; i++)	{
		big_span.addNumber(rand());
	}
	std::cout << big_span << std::endl;
	std::cout << big_span.shortestSpan() << std::endl;
	std::cout << big_span.longestSpan() << std::endl;
	
	return 0;
}