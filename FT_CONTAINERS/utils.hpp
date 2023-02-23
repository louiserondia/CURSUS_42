/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:11:39 by lrondia           #+#    #+#             */
/*   Updated: 2023/02/23 18:23:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft {

	template <typename T>
	void	swap(T &a, T &b) {
		T	tmp = a;

		a = b;
		b = tmp;
	}
	
}
