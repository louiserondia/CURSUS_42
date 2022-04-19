/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:30:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/19 20:29:41 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_action(t_info *info, char *cmd_name, char *file1)
{
	char	**cmd;
	char	*path;
	int		file_id;

	file_id = open(file1, O_RDONLY);
	if (file_id == -1)
		ft_exit(info, NULL, NULL, "open failed");
	cmd = ft_split(cmd_name, ' ');
	if (!cmd)
		ft_exit(info, NULL, NULL, "");
	path = get_path(info, cmd);
	dup2(file_id, STDIN_FILENO);
	dup2(info->fd[1], STDOUT_FILENO);
	ft_close(info);
	if (execve(path, cmd, info->envp) < 0)
		ft_exit(info, cmd, path, "execve failed");
}

void	next_action(t_info *info, int i)
{
	char	**cmd;
	char	*path;

	if (is_here_doc(info->argv[1]))
		cmd = ft_split(info->argv[i + 3], ' ');
	else
		cmd = ft_split(info->argv[i + 2], ' ');
	if (!cmd)
		ft_exit(info, NULL, NULL, "");
	path = get_path(info, cmd);
	dup2(info->fd[i * 2 - 2], STDIN_FILENO);
	dup2(info->fd[i * 2 + 1], STDOUT_FILENO);
	ft_close(info);
	if (execve(path, cmd, info->envp) < 0)
		ft_exit(info, cmd, path, "execve failed");
}

void	last_action(t_info *info, int i)
{
	char	**cmd;
	char	*path;

	if (is_here_doc(info->argv[1]))
		cmd = ft_split(info->argv[i + 3], ' ');
	else
		cmd = ft_split(info->argv[i + 2], ' ');
	if (!cmd)
		ft_exit(info, cmd, NULL, "open failed\n");
	path = get_path(info, cmd);
	dup2(info->fd[i * 2 - 2], STDIN_FILENO);
	dup2(info->last_id, STDOUT_FILENO);
	ft_close(info);
	if (execve(path, cmd, info->envp) < 0)
		ft_exit(info, cmd, path, "execve failed");
}
