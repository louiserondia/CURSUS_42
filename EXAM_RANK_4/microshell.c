/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:19:39 by lrondia           #+#    #+#             */
/*   Updated: 2023/01/25 17:20:56 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOC 5000

typedef	struct s_data
{
	char	**cmd;
	int		pipe_place;
	int		fd[2];
	int		pipes;
	int		sc;
	int		argc;
	char	**envp;
	int		tmp;
	
}	t_data;

void	free_all(char **tab)	{
	int i = 0;
	
	if (!tab)
		return;
	while (tab[i])	{
		free(tab[i]);
		i++;
	}
}

void	ft_exit(char **cmd, char *str)
{
	(void) cmd;
	printf("%s\n", str);
	// if (cmd)
	// 	free_all(cmd);
	// free(cmd);
	exit(EXIT_FAILURE);
}

void	debug_cmd(char **cmd)	{
	int i = 0;

	if (!cmd)
		return;
	printf("--------------------\n");
	while (cmd[i])
	{
		printf("cmd[%d] : %s\n", i, cmd[i]);
		i++;
	}
	printf("--------------------\n");
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

int	next_break_and_pipes_before(t_data *data, char **argv, int i)
{	
	while (argv[i])	{
		if (!strcmp("|", argv[i]))
			data->pipes++;
		if (!strcmp(";", argv[i]))
			break;
		i++;
	}
	return (i);
}

int	how_many_args_before_pipe(char **argv, int i)
{	
	int count = 0;
	
	while (argv[i])	{
		if (!strcmp("|", argv[i]))
			break;
		i++;
		count++;
	}
	return (count);
}

void	add_new_cmd(t_data *data, char *argv, int arg_in_cmd)
{
	int i = 0;

	data->cmd[arg_in_cmd] = malloc(sizeof (char) * ft_strlen(argv) + 1);
	while (argv[i])	{
		data->cmd[arg_in_cmd][i] = argv[i];
		i++;
	}
	data->cmd[arg_in_cmd][i] = '\0';
}

void	ft_fork(t_data *data)
{
	int	fork_id;

	pipe(data->fd);
	// printf("tmp : %d, fd[0] : %d et fd[1] : %d\n", data->tmp, data->fd[0], data->fd[1]);
	fork_id = fork();
	if (fork_id == -1)
		ft_exit(data->cmd, "Error");
	if (!fork_id)	{
		if (data->pipe_place)
			dup2(data->tmp, STDIN_FILENO);
		if (data->pipe_place != data->pipes) // pas a la fin
			dup2(data->fd[1], STDOUT_FILENO);
		close(data->tmp);
		close(data->fd[0]);
		close(data->fd[1]);
		if (execve(data->cmd[0], data->cmd, data->envp) == -1)
			ft_exit(data->cmd, "Error");
	}
	else	{
		close(data->tmp);
		data->tmp = data->fd[0];
		if (data->pipe_place == data->pipes)
			close(data->fd[0]);
		close(data->fd[1]);
		waitpid(-1, NULL, 0);
	}
}

void	pipe_routine(t_data *data, int arg_in_cmd)
{
	data->cmd[arg_in_cmd] = NULL;
	ft_fork(data);
	data->pipe_place++;
	free_all(data->cmd);
	free(data->cmd);
	data->cmd = malloc(sizeof (char *) * MALLOC);
}

int	one_phrase(t_data *data, char **argv, int begin)
{
	int i;
	int arg_in_cmd;
	int is_break;

	i = begin;
	arg_in_cmd = 0;
	is_break = next_break_and_pipes_before(data, argv, i);
	data->cmd = malloc(sizeof (char *) * MALLOC);
	while (argv[i] && i < is_break)
	{
		if (!strcmp("|", argv[i]))	{
			pipe_routine(data, arg_in_cmd);
			arg_in_cmd = 0;
			i++;
			continue;
		}
		if (argv[i])
			add_new_cmd(data, argv[i], arg_in_cmd);
		i++;
		arg_in_cmd++;
	}
	data->cmd[arg_in_cmd] = NULL;
	if (data->cmd[0])
		ft_fork(data);
	return (i);
}

void	parsing(t_data *data, char **argv)
{
	int	is_break;

	is_break = 1;
	while (~0)
	{
		is_break = one_phrase(data, argv, is_break);
		if (is_break >= data->argc)
			return;
		data->pipes = 0;
		data->pipe_place = 0;
		data->tmp = -1;
		free_all(data->cmd);
		free(data->cmd);
		is_break++;
		data->sc++;
	}
	
}
	
int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	data.sc = 0;

	data.argc = argc;
	data.envp = envp;
	data.tmp = -1;
	parsing(&data, argv);
	free_all(data.cmd);
	free(data.cmd);
	// system("leaks a.out");
	return (0);
}
