/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:13 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 18:10:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat(void);
		Cat(Cat const &copy);
		~Cat();

		Cat	&operator=(Cat const &rhs);
		
		void		makeSound(void) const;
		std::string	getType(void) const;
		Brain	&getBrain(void);
	private:
		Brain	*_brain;
};


#endif