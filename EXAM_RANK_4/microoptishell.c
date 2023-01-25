/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microoptishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:19:39 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/25 19:03:02 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef	struct s_data
{
	int		pipe_place;
	int		fd[2];
	int		pipes;
	char	**envp;
	int		tmp;
	
}	t_data;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void	ft_exit(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
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

void	run_child(t_data *data, char **argv)
{
	if (data->pipe_place) // pas au début
		dup2(data->tmp, STDIN_FILENO);
	if (data->pipe_place != data->pipes) // pas a la fin
		dup2(data->fd[1], STDOUT_FILENO);
	close(data->tmp);
	close(data->fd[0]);
	close(data->fd[1]);
	if (execve(argv[0], argv, data->envp) == -1)
		ft_exit("Error");
}

void	ft_fork(t_data *data, char **argv)
{
	int	fork_id;

	pipe(data->fd);
	fork_id = fork();
	if (fork_id == -1)
		ft_exit("Error");
	if (!fork_id)
		run_child(data, argv);
	else
	{
		close(data->tmp);
		data->tmp = data->fd[0];
		if (data->pipe_place == data->pipes)
			close(data->fd[0]);
		close(data->fd[1]);
		waitpid(-1, NULL, 0);
	}
}

char	**one_phrase(t_data *data, char **argv)
{
	int i;

	i = 0;
	while (argv[i] && strcmp(argv[i], ";"))
	{
		if (!strcmp("|", argv[i]))	{
			data->pipe_place++;
			argv[i] = NULL;
			ft_fork(data, argv);
			argv += i + 1;
			continue;
		}
		i++;
	}
	if (i)
		argv[i] = NULL;
	if (argv[0])
		ft_fork(data, argv);
	if (argv[i])
		argv += i + 1;
	else
		argv += 1;
	return (argv);
}

void	parsing(t_data *data, char **argv)
{
	argv++;
	while (~0)
	{
		argv = one_phrase(data, argv);
		if (!argv[0])
			return;
		data->pipes = 0;
		data->pipe_place = 0;
		data->tmp = -1;
	}
	
}
	
int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	(void) argc;
	data.envp = envp;
	data.tmp = -1;
	parsing(&data, argv);
	// system("leaks a.out");
	return (0);
}
