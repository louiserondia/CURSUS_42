/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:23:32 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/29 18:12:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)	{
	Harl	Harl;

	if (argc < 2)	{
		std::cout << "Please enter something Harl can complain about" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)	{
		Harl.complain(argv[i]);
		if (i + 1 < argc)
			std::cout << std::endl;
	}
	return (0);
}
