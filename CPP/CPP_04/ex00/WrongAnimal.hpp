/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:13 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 16:39:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &copy);
		~WrongAnimal();

		WrongAnimal	&operator=(WrongAnimal const &rhs);

		void			makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	type;
};


#endif