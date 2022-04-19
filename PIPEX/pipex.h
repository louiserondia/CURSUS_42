/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:24:17 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/19 19:59:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"

typedef struct s_info
{
	char	**argv;
	char	**envp;
	int		*fd;
	int		max;
	int		last_id;
}	t_info;

void	first_action(t_info *info, char *cmd_name, char *file1);
void	next_action(t_info *info, int i);
void	last_action(t_info *info, int i);
void	create_tab(t_info *info);
void	fork_and_wait(t_info *info);
void	ft_fork(t_info *info, int i);
char	*get_path(t_info *info, char **cmd);
void	ft_here_doc(t_info *info);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *src);
void	ft_free_matrix(char **matrix);
void	ft_exit(t_info *info, char **cmd, char *path, char *str);
void	ft_close(t_info *info);
int		is_here_doc(char *name);

#endif
