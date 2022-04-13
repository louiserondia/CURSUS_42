/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:09:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/13 19:09:58 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_here_doc(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		file_id;
	char	*line;

	if (argc != 6)
		exit(1);
	file_id = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (file_id == -1)
		exit(EXIT_FAILURE);
	line = get_next_line(0);
	while (line && ft_strncmp(line, argv[2], ft_strlen(argv[2])))
	{
		line = get_next_line(0);
		write (file_id, line, ft_strlen(line));
		free (line);
	}
	if (pipe(fd) == -1)
		exit (EXIT_FAILURE);
	first_action(fd, argv[4], argv[1], envp);
	last_action(fd, argv[5], argv[6], envp);
}
