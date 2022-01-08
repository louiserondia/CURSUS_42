/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:02:24 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/07 20:02:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*copy;

	i = 0:
	while (s[i])
	{
		copy = malloc(sizeof(char) * (f(i, s[i]) + 1));
		copy[i] = f(i, s[i]);
		i++;
	}
	return (copy);
}