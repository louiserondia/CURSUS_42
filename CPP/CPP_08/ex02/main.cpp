/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:35 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/18 13:04:04 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	MutantStack<int>::iterator it = mstack.begin();
	
	std::cout << "is empty : " << mstack.empty() << std::endl;
	mstack.push(1);
	std::cout << "is empty : " << mstack.empty() << std::endl;

	mstack.push(5);
	mstack.push(17);
	std::cout << "begin : " << *mstack.begin() << std::endl;
	mstack.pop();
	std::cout << "size : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator ite = mstack.end();
 	it = mstack.begin();

	++it;
	--it;
	std::cout << "mstack : ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);
	return 0;
}