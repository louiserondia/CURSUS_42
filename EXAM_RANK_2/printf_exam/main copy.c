/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:18:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/14 20:06:16 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		a;
	char	b;
	char	*c;

	a = -2147483648;
	b = 'c';
	c = "bonjour";
	ft_printf("%d\n", ft_printf("%p\n", &a));
	printf("%d\n", printf("%p\n", &a));
}
