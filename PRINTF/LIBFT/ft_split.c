/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:27:21 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/10 19:15:00 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_charset(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	ft_count_letters(const char *s, char c)
{
	int	i;
	int	letters;

	i = 0;
	letters = 0;
	while (s[i] && !ft_check_charset(s[i], c))
	{
		letters++;
		i++;
	}
	return (letters);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (!ft_check_charset(s[i], c)
			&& (ft_check_charset(s[i - 1], c) || i == 0))
		{
			words++;
			i++;
		}
		else
			i++;
	}
	return (words);
}

static void	*ft_free_all(char **lines, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**matrix;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	matrix = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!matrix)
		return (NULL);
	while (s[i] && j < ft_count_words(s, c))
	{
		while (ft_check_charset(s[i], c))
			i++;
		matrix[j] = malloc(sizeof(char) * (ft_count_letters(s + i, c) + 1));
		if (!matrix[j])
			return (ft_free_all(matrix, j));
		ft_strlcpy(matrix[j], s + i, (ft_count_letters(s + i, c) + 1));
		j++;
		i += ft_count_letters(s + i, c);
	}
	matrix[j] = 0;
	return (matrix);
}
