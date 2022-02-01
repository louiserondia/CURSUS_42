/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:47:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/02/01 19:32:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
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
		line[j] = str[i];
		i++;
		j++;
	}
	if (str[i] == '\n')
	{
		line[j] = str[i];
		j++;
	}
	line[j] = '\0';
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

char	*get_next_line(int fd)
{
	int			nbytes;
	char		*line;
	char		temp[BUFFER_SIZE + 1];
	static char	buffer[BUFFER_SIZE + 1];

	nbytes = BUFFER_SIZE;
	line = malloc(sizeof (char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	temp[0] = '\0';
	line = ft_strjoin(line, buffer);
	if (!line)
		return (NULL);
	while (!ft_strchr(line, '\n') && nbytes == BUFFER_SIZE)
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		temp[nbytes] = '\0';
		line = ft_strjoin(line, temp);
		if (!line)
			return (NULL);
	}
	cut_buffer(line, buffer);
	line = cut_line(line);
	return (line);
}
