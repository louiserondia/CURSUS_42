/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateFunctions.tpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:14:47 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/03 16:54:44 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;

    a = b;
    b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)    {
    return a < b ? a : b;
}

template <typename T>
T const &max(T const &a, T const &b)    {
    return a > b ? a : b;
}
