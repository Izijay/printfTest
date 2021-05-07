/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:32:46 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:19:21 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_transfer(t_input *input, char *str, va_list args)
{
	while (str[input->i])
	{
		init_flags(input);
		if (!str)
			break ;
		else if (str[input->i] == '%' && str[input->i + 1] )
		{
			ft_parse_format(str, input, args);
			if (ft_check_type(str[input->i]))
				treat_flags((char)input->type, input, args);
			else if (str[input->i])
				ft_noflags(input, str);
		}
		else if (str[input->i] != '%' && str[input->i])
			ft_noflags(input, str);
		input->i++;
	}
}

void		init_flags(t_input *input)
{
	input->minus = 0;
	input->star = 0;
	input->zero = 0;
	input->dot = 0;
	input->width = 0;
	input->type = 0;
	input->len_variable = 0;
	input->len_space = 0;
	input->b_dot = 0;
	input->dot_exist = 1;
	input->len_fill = 0;
}

void		treat_flags(char type, t_input *input, va_list args)
{
	if (type == 'c')
		treat_char(va_arg(args, int), input);
	if (type == 's')
		treat_string(va_arg(args, char*), input);
	if (type == '%')
		treat_char('%', input);
	if (type == 'p')
		treat_pointer(va_arg(args, unsigned long long), input);
	if (type == 'd' || type == 'i')
		treat_int(va_arg(args, int), input);
	if (type == 'u')
		treat_uint(va_arg(args, unsigned int), input);
	if (type == 'x' || type == 'X')
		treat_hexa(va_arg(args, unsigned int), input);
}

void		ft_parse_format(char *str, t_input *input, va_list args)
{
	while (str[++input->i])
	{
		if (!ft_check_flags(str[input->i]) && !ft_check_type(str[input->i])
				&& !ft_isdigit(str[input->i]))
			break ;
		if (str[input->i] == '0' && input->minus == 0 && input->width == 0)
			input->zero = 1;
		if (str[input->i] == '-')
			*input = ft_is_minus(*input);
		if (str[input->i] == '*')
			*input = ft_is_star(*input, args);
		if (str[input->i] == '.')
			*input = ft_is_dot(str ,input, args);
		if (ft_isdigit(str[input->i]))
			*input = ft_is_nbr(str[input->i], str[input->i - 1], *input, str);
		if (ft_check_type(str[input->i]))
		{
			input->type = str[input->i];
			break ;
		}
	}
	if (input->b_dot > 1)
		input->type = 0;
}

int			ft_printf(const char *format, ...)
{
		char	*str;
		t_input	input;
		va_list	args;

		input.index = 0;
		input.i = 0;
		input.ret_len = 0;
		str = ft_strdup(format);
		ft_bzero(input.buffer, 1024);
		va_start(args, format);
		ft_transfer(&input, str, args);
		va_end(args);
		free((char*)str);
		ft_display(&input);
		return (input.ret_len);
}
