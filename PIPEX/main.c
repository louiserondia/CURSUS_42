/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:02:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/12 19:26:11 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


#include <stdio.h>

char	*get_path(char **envp)
{
	int		i;
	char 	**path;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/cat");
		i++;
	}
	i = 0;
	while (path[i] && access(path[i], 0) == -1)
		i++;
	return (path[i]);
}

void	first_action(int fd[2], char *argv, char **envp)
{
	int		file_id;
	char	*path;
	char	**cmd;
	
	file_id = open("./file1", O_RDONLY);
	path = get_path(envp);
	cmd = ft_split(argv, ' ');
	dup2(file_id, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	ft_close(fd);
	execve(path, cmd, envp);
}

void	next_action(int fd[2], char *argv, char **envp)
{
	int		file_id;
	char	*path;
	char	**cmd;
	
	cmd = ft_split(argv, ' ');
	file_id = open("./file2", O_WRONLY);
	path = get_path(envp);
	dup2(fd[0], STDIN_FILENO);
	dup2(file_id, STDOUT_FILENO);
	ft_close(fd);
	execve(path, cmd, envp);
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
	{
		ft_close(fd);
		exit (EXIT_FAILURE);	
	}
	else if (!fork1)
		first_action(fd, argv[2], (char **)envp);
	fork2 = fork();
	if (fork2 == -1)
	{
		ft_close(fd);
		exit (EXIT_FAILURE);	
	}
	else if (!fork2)
		next_action(fd, argv[2], (char **)envp);
	ft_close(fd);
	waitpid(fork1, NULL, 0);
	waitpid(fork2, NULL, 0);
	return (0);
}
