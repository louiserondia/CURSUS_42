/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:20:46 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/29 16:23:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main(void)	{
	
	Data		*data1 = new Data;
	Data		*data2;
	uintptr_t	raw;

	data1->s = "yo";
	raw = serialize(data1);
	std::cout << "serialize: " << data1 << " -> " << raw << std::endl;
	data2 = deserialize(raw);
	
	std::cout << "deserialize: " << data1 << " == " << data2 << std::endl;
	std::cout << data1->s << " == " << data2->s << std::endl;
	
	return 0;
}
