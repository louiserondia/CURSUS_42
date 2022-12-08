/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:03:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 15:58:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const &copy);
		ClapTrap(std::string name);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		ClapTrap	&operator=(ClapTrap const &rhs);

	protected:
		std::string	_name;
		int			_max_hp;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
