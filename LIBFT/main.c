/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:02:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/05 18:42:27 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

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
	char test4[4] = "bon";
	char test5[4] = "abc";
	char test6[4] = "bon";
	char test7[4] = "abc";
	printf("%s\n", memcpy(test4, test5, 2));
	printf("%s\n", ft_memcpy(test6, test7, 2));
	printf("\n");

	printf("MEMMOVE\n");
	char	dest1[6] = "ABCDE";
	char	dest2[6] = "ABCDE";
	printf("%s\n", ft_memmove(dest2, test6, 3));
	printf("%s\n", dest2);
	printf("%s\n", memmove(dest1, test4, 3));
	printf("%s\n", dest1);
	printf("\n");

	printf("STRLCPY\n");
	char	oui[6] = "Prout";
	char	non[8] = "Bonjour";
	printf("%zu\n", ft_strlcpy(oui, non, 5));
	printf("%s\n", oui);
	printf("%zu\n", strlcpy(oui, non, 5));
	printf("%s\n", oui);
	printf("\n");

	printf("STRLCAT\n");
	char	test8[6] = "Prout";
	char	test9[8] = " Bonjour";
	printf("%zu\n", ft_strlcat(test8, test9, 5));
	printf("%s\n", test8);
	printf("%zu\n", strlcat(test8, test9, 5));
	printf("%s\n", test8);
	printf("\n");

	printf("TOUPPER\n");
	printf("%d\n", toupper(99));
	printf("%d\n", ft_toupper(99));
	printf("\n");
	
	printf("TOLOWER\n");
	printf("%d\n", tolower(67));
	printf("%d\n", ft_tolower(67));
	printf("\n");

	printf("STRCHR\n");
	printf("%s\n", strchr("hello World", 'l'));
	printf("%s\n", ft_strchr("hello World", 'l'));
	printf("\n");

	printf("STRRCHR\n");
	printf("%s\n", strrchr("hello World", 'l'));
	printf("%s\n", ft_strrchr("hello World", 'l'));
	printf("\n");

	printf("STRNCMP\n");
	printf("%d\n", ft_strncmp("bondour", "bonjour", 6));
	printf("%d\n", strncmp("bondour", "bonjour", 6));
	printf("\n");

	printf("MEMCHR\n");
	printf("%s\n", memchr("hello World", 'l', 4));
	printf("%s\n", ft_memchr("hello World", 'l', 4));
	printf("\n");

	printf("MEMCMP\n");
	char testa[15] = "bonjour";
	char testb[15] = "bonjour";
	printf("%d\n", ft_memcmp(testa, testb, 4));
	printf("%d\n", memcmp(testa, testb, 4));
	printf("\n");

	printf("STRNSTR\n");
	char testc[15] = "bonjour"; 
	char testd[15] = "ou";
	char *null1 = NULL;
	char *null2 = NULL;
	printf("%s\n", strnstr(testc, testd, 7));
	printf("%s\n", ft_strnstr(testc, testd, 7));
	printf("\n");

	printf("ATOI\n");
	char a[] = "    -21474836475";
	char b[] = "    -21474836475";	
	printf("%d\n", atoi(a));
	printf("%d\n", ft_atoi(b));
	printf("\n");
	
	printf("CALLOC\n");
	char c[] = "bonjour";
	char d[] = "    -21474836475";	
	printf("%s.\n", ft_calloc(2, 3));
	printf("%s.\n", calloc(2, 3));
	printf("\n");

	printf("STRDUP\n");
	printf("%s\n", strdup("bonjour la famille 0123456789 : ok !"));
	printf("%s\n", ft_strdup("bonjour la famille 0123456789 : ok !"));
	printf("\n");

	printf("SUBSTR\n");
	printf("%s\n", ft_substr("01234", 0, 5));
	printf("\n");

	printf("STRJOIN\n");
	printf("%s\n", ft_strjoin("louise", " rondia"));
	printf("\n");	
}
