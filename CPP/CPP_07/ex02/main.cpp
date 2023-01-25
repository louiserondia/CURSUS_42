/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:33:52 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/12 13:30:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750
int main(int, char **)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	Array<int> tmp = numbers;
	Array<int> test(tmp);

	for (int i = 0; i < MAX_VAL; i++)	{
		if (mirror[i] != numbers[i])	{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try    {
		numbers[-2] = 0;
	}
	catch (const std::exception &e)    {
		std::cerr << "-2: " << e.what() << '\n';
	}
	try    {
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)	{
		std::cerr << "MAX_VAL: " << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)	{
		numbers[i] = rand();
	}
	delete[] mirror;

	/////////////////////////////
	std::cout << "\n | My own tests | \n\n";
	/////////////////////////////

	Array<int> a(10);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;

	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";

	Array<int> b(a);
	
	std::cout << "\nb is a copy of a using copy constructor";
	std::cout << "\nb: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";

	Array<int> c = b;
	
	std::cout << "\nc is a copy of b using operator '='";
	std::cout << "\nc: ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	
	c[7] = 2;
	std::cout << "\n\nc[7] = 2 \n(showing that changing c won't affect b)" << std::endl;
	std::cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";

	std::cout << "\nc: ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	// system ("leaks Array");
	return 0;
}
