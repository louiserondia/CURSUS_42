/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:13 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 16:52:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const &copy);
		virtual ~Animal();

		Animal	&operator=(Animal const &rhs);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	type;
};


#endif