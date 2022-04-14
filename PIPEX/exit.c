/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:27:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/14 19:53:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free (matrix[i]);
		i++;
	}
}

void	ft_exit(int fd[2], char **cmd, char *path, char *str)
{
	close(fd[0]);
	close(fd[1]);
	perror(str);
	if (cmd)
		ft_free_matrix(cmd);
	if (path)
		free (path);
	exit(EXIT_FAILURE);
}

void	ft_close(int *fd)
{
	int	i;

	i = 0;
	while (fd[i] != -1)
	{
		close(fd[i]);
		i++;
	}
}
