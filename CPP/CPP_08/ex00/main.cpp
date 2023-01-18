/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/18 12:34:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	std::cout << "\n | TEST WITH A LIST | \n";
	std::list<int> list;

	std::cout << "list : ";
	for (int i = 2; i <= 8; i += 2)	{
		list.push_back(i);
		std::cout << *std::find(list.begin(), list.end(), i) << " ";
	}
	std::cout << std::endl;
	for (int i = 1; i <= 9; i++)	{
		try {
			std::cout  << *easyfind(list, i) << std::endl;
		}
		catch (std::out_of_range &e)	{
			std::cout << e.what() << " : " << i << std::endl;
		}
	}
	std::vector<int> vector;

	std::cout << "\n | SAME TEST WITH VECTOR | \n";
	std::cout << "vector : ";
	for (int i = 2; i <= 8; i += 2)	{
		vector.push_back(i);
		std::cout << *std::find(vector.begin(), vector.end(), i) << " ";
	}
	std::cout << std::endl;
	for (int i = 1; i <= 9; i++)	{
		try {
			std::cout  << *easyfind(vector, i) << std::endl;
		}
		catch (std::out_of_range &e)	{
			std::cout << e.what() << " : " << i << std::endl;
		}
	}
	return 0;
}
