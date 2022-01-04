/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:02:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/04 16:10:11 by lrondia          ###   ########.fr       */
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
	printf("%s\n", memset(test1, 49, 6));
	printf("%s\n", ft_memset(test1, 49, 6));
	printf("\n");
	
	printf("BZERO\n");
	char test2[8] = "bonjour";
	char test3[8] = "bonjour";
	bzero(test2, 3);
	printf("%c.\n", test2[4]);
	ft_bzero(test3, 3);
	printf("%c.\n", test3[4]);
	printf("\n");

	printf("MEMCPY\n");
	char *test4 = "bon";
	char *test5 = NULL;
	char *test6 = "bon";
	char *test7 = NULL;
	printf("%s\n", memcpy(test6, test7, 2));
	printf("%s\n", ft_memcpy(test4, test5, 2));
	printf("\n");

// 	printf("MEMMOVE\n");
// 	char	dest1[6] = "ABCDE";
// 	char	dest2[6] = "ABCDE";
// 	printf("%s\n", ft_memmove(dest2, test6, 3));
// 	printf("%s\n", dest2);
// 	printf("%s\n", memmove(dest1, test4, 3));
// 	printf("%s\n", dest1);
// 	printf("\n");

// 	printf("STRLCPY\n");
// 	char	oui[6] = "Prout";
// 	char	non[8] = "Bonjour";
// 	printf("%zu\n", ft_strlcpy(oui, non, 5));
// 	printf("%s\n", oui);
// 	printf("%zu\n", strlcpy(oui, non, 5));
// 	printf("%s\n", oui);
// 	printf("\n");

// 	printf("STRLCAT\n");
// 	char	test8[6] = "Prout";
// 	char	test9[8] = " Bonjour";
// 	printf("%zu\n", ft_strlcat(test8, test9, 5));
// 	printf("%s\n", test8);
// 	printf("%zu\n", strlcat(test8, test9, 5));
// 	printf("%s\n", test8);
// 	printf("\n");	
}
