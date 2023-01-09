/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:33:52 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/09 13:23:37 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include "Array.hpp"

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
		std::cerr << e.what() << '\n';
	}
	try    {
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)	{
		numbers[i] = rand();
	}
	delete[] mirror; //

	// Own tests

	Array<int> a(10);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	Array<int> b(a);
	Array<int> c = b;
	c[7] = 2;

	std::cout << "a: ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";

	std::cout << "\nb: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";

	std::cout << "\nc: ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	
	std::cout << "\nc[7] = 2;" << std::endl;
	std::cout << "b: ";
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";

	std::cout << "\nc: ";
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	return 0;
}
