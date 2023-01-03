/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/03 17:31:14 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.tpp"

template<typename T>
void	print(T &object)	{
	std::cout << "printing...	" << object << std::endl;
}

template<typename T>
void	add(T &object)	{
	object++;
}

int	main(void) {
	int	tab[3] = {1, 2, 3};

	iter(tab, 3, print);
	std::cout << "\nAdding one to each number of the table.\n" << std::endl;
	iter(tab, 3, add);
	iter(tab, 3, print);
	std::cout << "\nAdding one to each number of the table.\n" << std::endl;
	iter(tab, 3, add);
	iter(tab, 3, print);
	
	return 0;
}