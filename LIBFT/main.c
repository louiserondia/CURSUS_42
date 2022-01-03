/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:02:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/03 18:25:22 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int main()
{
	printf("ISALPHA\n");
	printf("%d\n", isalpha(9));
	printf("%d\n", ft_isalpha(9));
	printf("\n");
	
	printf("ISDIGIT\n");
	printf("%d\n", isdigit(50));
	printf("%d\n", ft_isdigit(50));
	printf("\n");

	printf("ISALNUM\n");
	printf("%d\n", isalnum(69));
	printf("%d\n", ft_isalnum(69));
	printf("\n");
	
	printf("ISASCII\n");
	printf("%d\n", isascii(169));
	printf("%d\n", ft_isascii(169));

	printf("\n");
	
	printf("ISPRINT\n");
	printf("%d\n", isprint(31));
	printf("%d\n", ft_isprint(31));
	printf("\n");

	printf("STRLEN\n");
	printf("%zu\n", strlen("bonjour"));
	printf("%zu\n", ft_strlen("bonjour"));
	printf("%zu\n", strlen(""));
	printf("%zu\n", ft_strlen(""));
	printf("\n");

	printf("MEMSET\n");
	char test1[8] = "bonjour";
	printf("%s\n", memset(test1, 49, 2));
	printf("%s\n", ft_memset(test1, 49, 2));
	printf("\n");
	
	printf("BZERO\n");
	char test2[8] = "bonjour";
	char test3[8] = "bonjour";
	bzero(test2, 3);
	printf("%c.\n", test2[4]);
	ft_bzero(test3, 3);
	printf("%c.\n", test3[4]);
	printf("\n");

	
}
