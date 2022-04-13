/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:02:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/13 19:09:59 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_action(int fd[2], char *cmd_name, char *file1, char **envp)
{
	char	**cmd;
	char	*path;
	int		file_id;

	file_id = open(file1, O_RDONLY);
	if (file_id == -1)
		ft_exit(fd, NULL, NULL, "open failed\n");
	cmd = ft_split(cmd_name, ' ');
	path = get_path(fd, envp, cmd);
	dup2(file_id, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed\n");
}

void	next_action(int fd[2], char *cmd_name, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(cmd_name, ' ');
	path = get_path(fd, envp, cmd);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed");
}

void	last_action(int fd[2], char *cmd_name, char *file2, char **envp)
{
	char	**cmd;
	char	*path;
	int		file_id;

	file_id = open(file2, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_id == -1)
		ft_exit(fd, NULL, NULL, "open failed\n");
	cmd = ft_split(cmd_name, ' ');
	path = get_path(fd, envp, cmd);
	dup2(fd[0], STDIN_FILENO);
	dup2(file_id, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed");
}


int	ft_fork(int max, int action, char **argv, char **envp, int fd[2])
{
	int		fork_id;

	fork_id = fork();
	if (fork_id == -1)
		ft_exit(fd, NULL, NULL, "Error\n");
	else if (!fork_id && action == 2)
		first_action(fd, argv[action], argv[1], envp);
	else if (!fork_id && action < max)
		next_action(fd, argv[action], envp);
	else if (!fork_id && action == max)
		last_action(fd, argv[action], argv[action + 1], envp);
	return(fork_id);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		id[5];
	int		action;

	action = 2;
	if (argc < 5)
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		ft_here_doc(argc, argv, envp);
	argc -= 2;
	while (action < argc)
	{
		if (pipe(fd) == -1)
			return (1);
		id[action - 2] = ft_fork(argc, action, argv, envp, fd);
		action++;
	}
	id[action - 2] = ft_fork(argc, action, argv, envp, fd);
	ft_close(fd, id, argc);
	return (0);
}
