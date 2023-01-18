/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/18 12:37:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n	| MY TESTS |\n";
	
	Span span(6);

	srand(time(NULL));
	span.addNumber(0);
	std::cout << "Span : " << span;
	try	{
		span.shortestSpan();
	}
	catch(const Span::SpanTooShortException &e)	{
		std::cerr << e.what() << '\n';
	}
	
	span.addNumber(10);
	span.addNumber(-1000);
	span.addNumber(-1);
	
	std::cout << "\nSpan : " << span;
	std::cout << "Shortest span : " << span.shortestSpan() << std::endl;
	std::cout << "Longest span : " << span.longestSpan() << std::endl;
	
	std::cout << "\n | TEST ON BIG SPAN | \n";

	std::vector<int>	v;
	for (int i = 0; i < 10000; i++)	{
		v.push_back(rand());
	}
	span.addNumbers(v.begin(), v.end());
	// std::cout << span << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	
	return 0;
}