/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:13 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 20:20:35 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		~Cat();
		void		makeSound(void) const;
		std::string	getType(void) const;
};


#endif