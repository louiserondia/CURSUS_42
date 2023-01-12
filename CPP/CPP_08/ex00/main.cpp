/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/10 14:13:09 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void) {
	std::list<int> list;
	
	for (int i = 2; i <= 7; i++)
		list.push_back(i);
	
	// std::cout << *std::find(list.begin(), list.end(), 4) << std::endl;
	std::cout  << *easyfind(list, 3) << std::endl;
	try {
		std::cout  << *easyfind(list, 10) << std::endl;
	}
	catch (std::out_of_range &e)	{
		std::cout << e.what() << " : 10\n";
	}
	return 0;
}