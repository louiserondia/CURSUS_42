/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:02:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/13 14:40:21 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**write_path(int fd[2], char **envp, char **cmd)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		ft_exit(fd, cmd, NULL, "");
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd[0]);
		if (!path[i])
			ft_exit(fd, cmd, NULL, "");
		i++;
	}
	return (path);
}

char	*get_path(int fd[2], char **envp, char **cmd)
{
	int		i;
	char	**path;
	char	*right_path;

	i = 0;
	path = write_path(fd, envp, cmd);
	while (path[i] && access(path[i], 0) == -1)
		i++;
	right_path = ft_strdup(path[i]);
	if (!right_path)
	{
		ft_free_matrix(path);
		ft_exit(fd, cmd, NULL, "");
	}
	ft_free_matrix(path);
	return (right_path);
}

void	first_action(int fd[2], char *cmd_name, char **envp)
{
	char	**cmd;
	char	*path;
	int		file_id;

	file_id = open("./file1", O_RDONLY);
	if (file_id == -1)
		ft_exit(fd, NULL, NULL, "open failed\n");
	cmd = ft_split(cmd_name, ' ');
	path = get_path(fd, envp, cmd);
	dup2(file_id, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	ft_close(fd);
	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed\n");
}

void	next_action(int fd[2], char *cmd_name, char *file2, char **envp)
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
	ft_close(fd);
	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		fork1;
	int		fork2;

	if (argc < 5)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	fork1 = fork();
	if (fork1 == -1)
		ft_exit(fd, NULL, NULL, "Error\n");
	else if (!fork1)
		first_action(fd, argv[2], (char **)envp);
	fork2 = fork();
	if (fork2 == -1)
		ft_exit(fd, NULL, NULL, "Error\n");
	else if (!fork2)
		next_action(fd, argv[3], argv[4], (char **)envp);
	ft_close(fd);
	waitpid(fork1, NULL, 0);
	waitpid(fork2, NULL, 0);
	return (0);
}
