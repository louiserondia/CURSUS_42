/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:26:44 by lrondia           #+#    #+#             */
/*   Updated: 2023/05/03 14:50:07 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Warlock {

	private:

		std::string	_name;
		std::string	_title;

		Warlock();
		Warlock(const Warlock &);
		Warlock &operator=(const Warlock &);

	public:

		Warlock(const std::string &name, const std::string &title);

		~Warlock();

		const std::string	&getName() const;
		const std::string	&getTitle() const;
		void		setTitle(const std::string &title);

		void		introduce() const;

};

