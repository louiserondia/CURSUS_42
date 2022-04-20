/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:14:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/20 17:18:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**write_path(t_info *info, char **cmd)
{
	int		i;
	char	**path;

	i = 0;
	while (info->envp[i] && !ft_strnstr(info->envp[i], "PATH=",
			ft_strlen(info->envp[i])))
		i++;
	path = ft_split(info->envp[i] + 5, ':');
	if (!path)
		ft_exit(info, cmd, NULL, "");
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd[0]);
		if (!path[i])
			ft_exit(info, cmd, NULL, "");
		i++;
	}
	return (path);
}

char	*get_path(t_info *info, char **cmd)
{
	int		i;
	char	**path;
	char	*right_path;

	i = 0;
	if (access(cmd[0], X_OK) != -1)
		return (cmd[0]);
	path = write_path(info, cmd);
	while (path[i] && access(path[i], X_OK) == -1)
		i++;
	right_path = ft_strdup(path[i]);
	if (!right_path)
	{
		ft_free_matrix(path);
		ft_exit(info, cmd, NULL, "");
	}
	ft_free_matrix(path);
	return (right_path);
}
