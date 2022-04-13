/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:24:17 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/13 18:46:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"

void	first_action(int fd[2], char *cmd_name, char *file1, char **envp);
void	last_action(int fd[2], char *cmd_name, char *file2, char **envp);
char	*get_path(int fd[2], char **envp, char **cmd);
void	ft_here_doc(int argc, char **argv, char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *src);
void	ft_free_matrix(char **matrix);
void	ft_exit(int fd[2], char **cmd, char *path, char *str);
void	ft_close(int fd[2], int ids[2], int max);

#endif
