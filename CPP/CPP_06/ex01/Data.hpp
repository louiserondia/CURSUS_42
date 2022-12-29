/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:24:40 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/29 15:43:07 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
	public:
		std::string	s;

		Data(void);
		Data(Data const &src);
		~Data(void);

		Data		&operator=(Data const &rhs);

	private:
};

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

#endif
