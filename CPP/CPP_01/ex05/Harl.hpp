/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:54:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/29 16:21:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
private:
	
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

public:

	Harl(void);
	~Harl(void);

	void	complain(std::string level);
};

#endif
