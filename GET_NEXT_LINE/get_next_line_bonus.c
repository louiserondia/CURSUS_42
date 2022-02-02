/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:47:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/02 18:41:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*cut_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof (char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}	
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free (str);
	return (line);
}

void	cut_buffer(char *str, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!buffer)
		return ;
	while (str[i])
	{
		buffer[j] = str[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*read_line(int fd, char *line)
{
	int		nbytes;
	char	temp[BUFFER_SIZE + 1];

	nbytes = BUFFER_SIZE;
	temp[0] = '\0';
	while (!ft_strchr(line, '\n') && nbytes == BUFFER_SIZE)
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (line);
			return (NULL);
		}
		temp[nbytes] = '\0';
		line = ft_strjoin(line, temp);
		if (!line)
			return (NULL);
	}
	if (nbytes == 0 && line [0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	line = malloc(sizeof (char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_strjoin(line, buffer[fd]);
	if (!line)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	cut_buffer(line, buffer[fd]);
	line = cut_line(line);
	return (line);
}
