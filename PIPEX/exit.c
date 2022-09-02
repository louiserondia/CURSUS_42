/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:27:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/13 19:48:56 by lrondia          ###   ########.fr       */
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

void	ft_exit(t_info *info, char **cmd, char *path, char *str)
{
	if (info)
		ft_close(info);
	perror(str);
	if (path)
		free (path);
	if (cmd)
		ft_free_matrix(cmd);
	if (info && info->fd)
		free(info->fd);
	exit(EXIT_FAILURE);
}

void	ft_close(t_info *info)
{
	int	i;

	i = 0;
	while (i < (info->max - 1) * 2)
	{
		close(info->fd[i]);
		i++;
	}
}
