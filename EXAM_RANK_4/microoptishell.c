/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microoptishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:19:39 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/27 19:51:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef	struct s_data
{
	int		pipes;
	int		pipe_place;
	int		fd[2];
	int		fd_tmp;
	char	**envp;
	
}	t_data;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return i;
}

void	debug_cmd(char **cmd)	{
	int i = 0;

	if (!cmd)
		return;
	printf("-------------------\n");
	while (cmd[i])
	{
		printf("cmd[%d] : %s\n", i, cmd[i]);
		i++;
	}
	if (!cmd[0])
	printf("---    empty    ---\n");
	printf("-------------------\n");
}

void	ft_exit(char *str, char *arg)
{
	write(2, str, ft_strlen(str));
	if (arg)
		write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	how_many_pipes(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->pipes = 0;
	while (argv[i] && strcmp(argv[i], ";"))
	{
		if (!strcmp(argv[i], "|"))
			data->pipes++;
		i++;
	}	
}

void	run_child(t_data *data, char **argv, char *envp[])
{
	if (data->pipe_place) // FIN & MILIEU
		dup2(data->fd_tmp, STDIN_FILENO);
	if (data->pipe_place != data->pipes) // DEBUT & MILIEU
		dup2(data->fd[1], STDOUT_FILENO);
	close(data->fd_tmp);
	close(data->fd[0]);
	close(data->fd[1]);
	if (execve(argv[0], argv, envp) == -1)
		ft_exit("error : cannot execute ", argv[0]);
}

void	handle_cd(char **argv)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (argv[i] && strcmp(argv[i], "|"))
		i++;
	if (i != 2)
		write(2, "error: cd: bad arguments\n", 25);
	res = chdir(argv[1]);
	if (res == -1)	{
		write(2, "error: cd: cannot change directory to ", 39);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
	}
	if (argv[i] && !strcmp(argv[i], "|"))
		i++;
	// return (argv + i);
}

void	ft_fork(t_data *data, char *argv[], char *envp[])
{
	int	fork_id;

	if (!strcmp(argv[0], "cd"))	{
		handle_cd(argv);
		return;
	}
	if (!argv || !argv[0])
		return;
	pipe(data->fd);
	fork_id = fork();
	if (fork_id == -1)
		ft_exit("error: fatal", NULL);
	if (!fork_id)
		run_child(data, argv, envp);
	else
	{
		close(data->fd_tmp);
		data->fd_tmp = data->fd[0];
		if (data->pipe_place == data->pipes)
			close(data->fd[0]);
		close(data->fd[1]);
		waitpid(-1, NULL, 0);
	}
}

char	**one_phrase(t_data *data, char *argv[], char *envp[])
{
	int 	i;
	bool	is_break;

	i = 0;
	is_break = false;
	while (argv[i] && strcmp(argv[i], ";"))
	{
		if (!strcmp("|", argv[i]))	{
			argv[i] = NULL;
			ft_fork(data, argv, envp);
			data->pipe_place++;
			argv += i + 1;
			i = 0;
			continue;
		}
		i++;
	}
	if (argv[i] && !strcmp(argv[i], ";"))
		is_break = true;
	if (argv[0])	{
		argv[i] = NULL;
		ft_fork(data, argv, envp);
		if (is_break)
			i++;
		argv += i;
	}
	return (argv);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	(void) argc;
	argv++;
	while (argv[0])
	{
		data.fd_tmp = -1;
		data.pipe_place = 0;
		how_many_pipes(&data, argv);
		argv = one_phrase(&data, argv, envp);
	}
	return (0);
}
