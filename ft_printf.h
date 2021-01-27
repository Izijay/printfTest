/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:12:16 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/26 03:50:40 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct		s_input
{
	int		parse;
	int		width;
	int		type;
	int		zero;
	int		dot;
	int		minus;
	int		asterisk;
}					t_input;

int			ft_printf(const char *format, ...);
int			check_type(int c);
int			check_flags(int c);
int			treat_all(int c, t_input input, va_list args);
int			type_char(char c, t_input input);
int			type_string(char *str, t_input input);
int			type_int(int i, t_input input);
int			type_percent(t_input input);
int			type_hexa(unsigned int i, int lower, t_input input);
int			type_uint(unsigned int i, t_input input);
int			type_pointer(unsigned long long pointer, t_input input);
int			ft_putchar(int c);
int			ft_width(int width, int minus, int zero);
int			putstr_preci(char *str, int preci);

int			flag_dot(const char *str, int start, t_input *input, va_list args);
t_input		flag_minus(t_input input);
t_input		flag_width(va_list args, t_input input);
t_input		flag_digit(char c, t_input input);

char		*ft_uitoa(unsigned int nbr);

#endif
