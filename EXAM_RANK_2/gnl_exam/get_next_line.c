/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:34:43 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/15 18:37:44 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	new_buffer(char *buffer, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i] && j < BUFFER_SIZE - 1)
	{
		buffer[j] = line [i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*new_line(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	new_line = malloc(sizeof (char) * i + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free (line);
	return (new_line);
}

char	*read_line(int fd, char	*line)
{
	int		nbytes;
	char	*temp;

	nbytes = BUFFER_SIZE;
	while (nbytes == BUFFER_SIZE && !ft_strchr('\n', line))
	{
		temp = malloc (sizeof (char) * BUFFER_SIZE + 1);
		if (!temp)
			return (NULL);
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (line);
			free (temp);
			return (NULL);
		}
		temp[nbytes] = '\0';
		line = ft_strjoin(line, temp);
		free (temp);
		if (!line)
			return (NULL);
	}
	if (!temp[0] && !line[0])
	{
		free (line);
		return (NULL);
	}	
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE == 0)
		return (NULL);
	line = malloc(sizeof (char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	line = ft_strjoin(line, buffer);
	if (!line)
		return (NULL);
	line = read_line(fd, line);
	if (!line)
		return (NULL);
	new_buffer(buffer, line);
	line = new_line(line);
	return (line);
}
