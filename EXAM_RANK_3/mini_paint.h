/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:40:30 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/01 18:48:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
#define MINI_PAINT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct t_tab {
	int		size_x;
	int		size_y;
	int		x;
	int		y;
	char	type;
	char	content;
	float	radius;
	char	*tab;
}	t_tab;

#endif