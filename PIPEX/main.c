/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:02:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/05/03 15:35:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_tab(t_info *info)
{
	int	i;

	i = 0;
	info->fd = malloc(sizeof(int) * (info->max - 1) * 2);
	if (!info->fd)
		exit(EXIT_FAILURE);
	while (i < info->max - 1)
	{
		pipe(info->fd + (i * 2));
		i++;
	}
}

void	ft_fork(t_info *info, int i)
{
	char	*name;
	int		fork_id;

	name = info->argv[1];
	fork_id = fork();
	if (fork_id == -1)
		ft_exit(info, NULL, NULL, "Error\n");
	else if (!fork_id && i == 0 && is_here_doc(name))
		first_action(info, info->argv[3], info->argv[1]);
	else if (!fork_id && i == 0)
		first_action(info, info->argv[2], info->argv[1]);
	else if (!fork_id && i < info->max - 1)
		next_action(info, i);
	else if (!fork_id && i == info->max - 1)
		last_action(info, i);
}

void	fork_and_wait(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->max)
	{
		ft_fork(info, i);
		i++;
	}
	ft_close(info);
	free (info->fd);
	i = 0;
	while (i < info->max)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	info.argv = argv;
	info.envp = envp;
	if (argc < 5)
		return (1);
	if (is_here_doc(argv[1]))
	{
		info.max = argc - 4;
		info.last_id = open(info.argv[info.max + 3],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (info.last_id == -1)
			ft_exit(NULL, NULL, NULL, "open failed\n");
		ft_here_doc(&info);
	}
	info.max = argc - 3;
	info.last_id = open(info.argv[info.max + 2],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (info.last_id == -1)
		ft_exit(NULL, NULL, NULL, "open failed\n");
	create_tab(&info);
	fork_and_wait(&info);
	return (0);
}
