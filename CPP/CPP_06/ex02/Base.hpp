/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:24:40 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/29 16:52:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base
{
	public:
		virtual ~Base(void);

	private:
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
