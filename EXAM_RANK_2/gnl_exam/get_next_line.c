/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 12:13:11 by lrondia           #+#    #+#             */
/*   Updated: 2022/03/16 12:55:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc (sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free (s1);
	return (str);
}
#include <stdio.h>

char	*get_line(char *temp)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	while (j < i)
	{
		line[j] = temp[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

void	get_buffer(char *temp, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	while (temp[i])
	{
		buffer[j] = temp[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*line;
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
	   	return (NULL);
	nbytes = BUFFER_SIZE;
	buf[0] = '\0';
	temp = malloc(sizeof (char) * 1);
	temp[0] = '\0';
	temp = ft_strjoin(temp, buffer);
	while (nbytes > 0 && !ft_strchr(temp, '\n'))
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (temp);
			return (NULL);
		}
		buf[nbytes] = '\0';
		temp = ft_strjoin(temp, buf);
	}
	if (nbytes == 0 && temp[0] == '\0')
	{
		free (temp);
		return (NULL);
	}
	line = get_line(temp);
	get_buffer(temp, buffer);
	free (temp);
	return (line);

}

