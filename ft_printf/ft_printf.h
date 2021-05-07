/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:51:41 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:18:15 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_input
{
		int			minus;
		int			star;
		int			zero;
		int			dot;
		int			width;
		int			index;
		int			type;
		int			i;
		int			ret_len;
		int			len_variable;
		int			len_space;
		int			b_dot;
		int			dot_exist;
		int			len_fill;
		char		buffer[1024];
}					t_input;

int						ft_printf(const char *format, ...);
void					ft_parse_format(char *str, t_input *input, va_list args);
void					treat_flags(char type, t_input *input, va_list args);
void					init_flags(t_input *input);
void					ft_transfer(t_input *input, char *str, va_list args);
int						ft_check_flags(char c);
int						ft_check_type(char c);
void					ft_display(t_input *input);
void					ft_buffering(t_input *input, char *str, int len);
void					ft_noflags(t_input *input, char *str);
t_input					ft_is_minus(t_input input);
t_input					ft_is_star(t_input input, va_list args);
t_input					ft_is_dot(char *str, t_input *input, va_list args);
t_input					ft_is_nbr(char c, char d, t_input input, char *str);
void					ft_is_plus(t_input *input);
char					*treat_width(t_input *input);
void					treat_char(char c, t_input *input);
char					*ft_chartostr(char c);
void					treat_string(char *str, t_input *input);
void					treat_pointer(unsigned long long nbr, t_input *input);
char					*ft_ulltoa_base(unsigned long long nbr);
int						ft_nblen(unsigned long long nbr);
char					*ft_add_fill(t_input *input);
void					treat_int(int nbr, t_input *input);
void					treat_uint(unsigned int nbr, t_input *input);
char					*ft_fill_u(t_input *input);
void					treat_hexa(unsigned int nbr, t_input *input);

#endif
