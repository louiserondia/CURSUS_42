/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:54:50 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/09 18:13:18 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &copy);
		virtual ~Brain();

		Brain	&operator=(Brain const &rhs);
		void	hasNewIdea(std::string idea);
		void	printIdeas(void);

	private:
		std::string	ideas[100];
		int			index;
};

#endif