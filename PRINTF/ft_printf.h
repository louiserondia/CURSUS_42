/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:14:05 by lrondia           #+#    #+#             */
/*   Updated: 2022/01/26 20:36:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int	is_sharp;
	int	is_plus;
	int	is_space;
	int	is_minus;
	int	is_zero;
	int	is_x;
	int	is_negative;
	int	precision;
	int	width;
	int	count;
}	t_flags;

int		ft_printf(const char *format, ...);
t_flags	init_flags(void);
int		is_flag(char c);
int		is_conversion(char c, t_flags *flags);
void	check_char(const char *format, va_list arg, int *i, t_flags *flags);
void	sort_char(char c, va_list arg, t_flags *flags);
void	set_flag(char c, t_flags *flags);
void	ft_puthexa_fd(unsigned long n, int fd, int (*f)(int));
int		ft_nbrlen(long n);
int		ft_unsignedlen(unsigned int n);
int		ft_hexalen(unsigned long n);
void	add_prefix_address(t_flags *flags);
void	ft_putstrl(char *s, int len, t_flags *flags);
void	ft_putunsigned_fd(unsigned int n, int fd);
void	print_sign(t_flags *flags, long *value);
int		return_padding_str(t_flags *flags, char *value);
int		return_padding_int(t_flags *flags, long value);
int		return_padding_unsigned(t_flags *flags, unsigned int value);
int		return_padding_hex(t_flags *flags, unsigned int value);
int		return_padding_ptr(t_flags *flags, unsigned long value);
int		padding_zero(int padding, int max);
int		padding_space(int padding, int max);
void	reset_flags(t_flags *flags);
void	conversion_char(va_list arg, t_flags *flags);
void	conversion_str(va_list arg, t_flags *flags);
void	conversion_int(va_list arg, t_flags *flags);
void	conversion_unsigned(va_list arg, t_flags *flags);
void	conversion_ptr(va_list arg, t_flags *flags);
void	conversion_hex(va_list arg, int (*f)(int), t_flags *flags);
void	conversion_percent(t_flags *flags);
void	check_plus(t_flags *flags, int value);
void	check_space(t_flags *flags, int value);
void	check_sharp(t_flags *flags, unsigned int value);
void	check_width(t_flags *flags, int padding);
void	check_precision_str(t_flags *flags, char *value);
void	check_precision_int(t_flags *flags, long value);
void	check_precision_unsigned(t_flags *flags, unsigned int value);
void	check_precision_hex(t_flags *flags, unsigned int value);
void	check_precision_ptr(t_flags *flags, unsigned long value);
void	check_zero_int(t_flags *flags, long value);
void	check_zero_unsigned(t_flags *flags, unsigned int value);
void	check_zero_hex(t_flags *flags, unsigned int value);
void	check_zero_percent(t_flags *flags);
void	check_minus_char(t_flags *flags);
void	check_minus_str(t_flags *flags, char *value);
void	check_minus_int(t_flags *flags, long value);
void	check_minus_unsigned(t_flags *flags, unsigned int value);
void	check_minus_hex(t_flags *flags, unsigned int value);
void	check_minus_ptr(t_flags *flags, unsigned long value);
void	check_minus_percent(t_flags *flags);

#endif
