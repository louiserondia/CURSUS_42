/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:57:08 by lrondia           #+#    #+#             */
/*   Updated: 2022/04/13 19:04:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**write_path(int fd[2], char **envp, char **cmd)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
		i++;
	path = ft_split(envp[i] + 5, ':');
	if (!path)
		ft_exit(fd, cmd, NULL, "");
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd[0]);
		if (!path[i])
			ft_exit(fd, cmd, NULL, "");
		i++;
	}
	return (path);
}

char	*get_path(int fd[2], char **envp, char **cmd)
{
	int		i;
	char	**path;
	char	*right_path;

	i = 0;
	path = write_path(fd, envp, cmd);
	while (path[i] && access(path[i], 0) == -1)
		i++;
	right_path = ft_strdup(path[i]);
	if (!right_path)
	{
		ft_free_matrix(path);
		ft_exit(fd, cmd, NULL, "");
	}
	ft_free_matrix(path);
	return (right_path);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i] && i < n)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{	
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		i = 0;
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*ptr;

	i = 0;
	while (src[i])
		i++;
	ptr = malloc(sizeof(src[0]) * i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (src[i])
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
