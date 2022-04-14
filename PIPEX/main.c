/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:02:19 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/14 20:01:19 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_action(int *fd, char *cmd_name, char *file1, char **envp)
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
	ft_close(fd);
	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed\n");
}

void	next_action(int *fd, char **argv, int i, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[i + 2], ' ');
	path = get_path(fd, envp, cmd);
	dup2(fd[i * 2 - 2], STDIN_FILENO);
	dup2(fd[i * 2 + 1], STDOUT_FILENO);
	ft_close(fd);

	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed");
}

void	last_action(int *fd, char **argv, int i, char **envp)
{
	char	**cmd;
	char	*path;
	int		file_id;

	file_id = open(argv[i + 3], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_id == -1)
		ft_exit(fd, NULL, NULL, "open failed\n");
	cmd = ft_split(argv[i + 2], ' ');
	path = get_path(fd, envp, cmd);
	printf("i %d\n", i);
	printf("i %d\n", (i * 2 - 2));
	//dup2(fd[i * 2 - 2], STDIN_FILENO);
	dup2(fd[0], STDOUT_FILENO);
	dup2(file_id, STDOUT_FILENO);
	ft_close(fd);
	if (execve(path, cmd, envp) < 0)
		ft_exit(fd, cmd, path, "execve failed");
}


int	*create_tab(int argc)
{
	int	i;
	int	*fd;
	int	nb_args;

	i = 0;
	nb_args = argc - 3;
	fd = malloc(sizeof(int) * (nb_args - 1) * 2 + 1);
	if (!fd)
		exit(EXIT_FAILURE);
	while (i < nb_args - 1)
	{
		pipe(fd + (i * 2));
		i++;
	}
	fd[(nb_args - 1) * 2 + 1] = -1;
	return (fd);
}

int	ft_fork(int *fd, int max, int i, char **argv, char **envp)
{
	int	fork_id;

	fork_id = fork();
	if (fork_id == -1)
		ft_exit(fd, NULL, NULL, "Error\n");
	else if (!fork_id && i == 0)
		first_action((fd), argv[i + 2], argv[1], envp);
	else if (!fork_id && i < max)
		next_action(fd, argv, i, envp);
	else if (!fork_id && i == max)
		last_action(fd, argv, i, envp);
	else if (!fork_id && i == 0)
		last_action_heredoc(fd, argv[max - 1], argv[max], envp);
	return(fork_id);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	*fd;

	i = 0;
	if (argc < 5)
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
		ft_here_doc(argc, argv, envp);
	fd = create_tab(argc);
	while (i < argc - 3)
	{
		ft_fork(fd, argc - 4, i, argv, envp);
		i++;
	}
	ft_close(fd);
	free (fd);
	i = 0;
	while (i < argc - 3)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
	return (0);
}
