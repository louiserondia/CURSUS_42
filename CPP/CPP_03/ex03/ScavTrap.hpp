/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:03:35 by lrondia           #+#    #+#             */
/*   Updated: 2022/12/08 18:48:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const &copy);
		ScavTrap(std::string name);
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate();
		
		ScavTrap	&operator=(ScavTrap const &rhs);

	private:
};

#endif
