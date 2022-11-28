/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:08:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/28 12:13:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)	{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "string address = " << &string << std::endl;
	std::cout << "stringPTR address = " << stringPTR << std::endl;
	std::cout << "stringREF address = " << &stringREF << std::endl;

	std::cout << "string value = " << string << std::endl;
	std::cout << "stringPTR value = " << *stringPTR << std::endl;
	std::cout << "stringREF value = " << stringREF << std::endl;
}