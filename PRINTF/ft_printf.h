/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:14:05 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/19 16:49:09 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./LIBFT/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int	is_sharp;
	int	is_plus;
	int	is_space;
	int	is_minus;
	int	is_zero;
	int	is_dot;
	int	width;
	int	count;
}	t_flags;

int		ft_printf(const char *format, ...);
int		check_conversion(char c);
void	check_char(const char *format, va_list arg, int *i, t_flags *flags);
void	sort_char(char c, va_list arg, t_flags *flags);
void	set_flag(char c, t_flags *flags);
void	ft_puthexa_fd(unsigned long n, int fd, int (*f)(int));
int		ft_nbrlen(long n);
int		ft_hexalen(unsigned long n);
void	add_prefix_address(t_flags *flags);
void	ft_putunsigned_fd(unsigned int n, int fd);
t_flags	init_flags(void);
void	conversion_char(va_list arg, t_flags *flags);
void	conversion_str(va_list arg, t_flags *flags);
void	conversion_int(va_list arg, t_flags *flags);
void	conversion_unsigned(va_list arg, t_flags *flags);
void	conversion_ptr(va_list arg, t_flags *flags);
void	conversion_hex(va_list arg, int (*f)(int), t_flags *flags);
void	conversion_percent(t_flags *flags);
void	check_flags(char c, t_flags *flags, va_list arg);
void	check_sharp(char c, t_flags *flags);
void	check_plus(char c, t_flags *flags, va_list arg);
void	check_space(char c, t_flags *flags, va_list arg);
void	check_width(char c, t_flags *flags, va_list arg);


void	debug(t_flags *flags);

#endif
