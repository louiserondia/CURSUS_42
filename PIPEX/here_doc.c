/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:09:59 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/19 19:01:19 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_stdin(t_info *info, int file_id)
{
	char	*line;

	line = get_next_line(0);
	while (line && !(!ft_strncmp(line, info->argv[2], ft_strlen(info->argv[2]))
			&& ft_strlen(line) - 1 == ft_strlen(info->argv[2])))
	{
		write (file_id, line, ft_strlen(line));
		line = get_next_line(0);
		free (line);
	}
}

void	ft_here_doc(t_info *info)
{
	int	file_id;

	file_id = open(info->argv[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_id == -1)
		exit(EXIT_FAILURE);
	read_stdin(info, file_id);
	create_tab(info);
	fork_and_wait(info);
	unlink(info->argv[1]);
	exit (EXIT_SUCCESS);
}
