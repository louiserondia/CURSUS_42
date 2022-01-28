/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:47:14 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/28 17:00:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char *get_next_line(int fd)
{
	int		i;
	int		nbytes;
	char	*temp;

	i = 0;
	nbytes = 1;
	while (!is_new_line(temp) || !nbytes)
	{
		nbytes = read(fd, temp, BUFFER_SIZE)
		if (nbytes == -1)
			return (NULL);
		i++;
	}
}
