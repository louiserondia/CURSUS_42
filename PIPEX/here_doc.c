/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:09:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/14 17:16:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_here_doc(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		id[5];
	int		file_id;
	char	*line;

	if (argc != 6)
		exit(1);
	file_id = open(argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_id == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(0);
	while (line && !(!ft_strncmp(line, argv[2], ft_strlen(argv[2]))
		&& ft_strlen(line) - 1 == ft_strlen(argv[2])))
	{
		write (file_id, line, ft_strlen(line));
		line = get_next_line(0);
		free (line);
	}
	if (pipe(fd) == -1)
		exit (EXIT_FAILURE);
	id[0] = ft_fork(fd, 5, 4, argv, envp);
	id[1] = ft_fork(fd, 0, 6, argv, envp);
	ft_close(fd);
	waitpid(-1, NULL, 0);
	exit (EXIT_SUCCESS);
}

void	last_action_heredoc(int fd[2], char *cmd_name, char *file2, char **envp)
{
	char	**cmd;
	char	*path;
	int		file_id;

	printf("%s\n", file2);
	file_id = open(file2, O_CREAT | O_WRONLY | O_APPEND, 0644);
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
