/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:12:05 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/19 15:02:39 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_input			init_struct(void)
{
	t_input		input;

	input.dot = -1;
	input.minus = 0;
	input.asterisk = 0;
	input.type = 0;
	input.width = 0;
	input.zero = 0;
	return (input);
}

int				parse_flag(const char *str, int i, t_input *input, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !check_type(str[i])
			&& !check_flags(str[i]))
			break ;
		if (str[i] == '0' && input->width == 0 && input->minus == 0)
			input->zero == -1;
		if (str[i] == '.')
			i = flag_dot(str, i, input, args);
		if (str[i] == '-')
			*input = flag_minus(*input);
		if (str[i] == '*')
			*input = flag_width(args, *input);
		if (ft_isdigit(str[i]))
			*input = flag_digit(str[i], *input);
		if (check_type(str[i]))
		{
			input->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int				parse_str(const char *str, va_list args)
{
	int			i;
	t_input		input;
	int			count;

	i = 0;
	count = 0;
	while (1)
	{
		input = init_struct();
		if (!str[i])
			break ;
		else if (str[i] == '%' && str [i + 1])
		{
			i = parse_flag(str, ++i, &input, args);
			if (check_type(str[i]))
				count = count + treat_all((char)input.type, input, args);
			else if (str[i])
				count = count + ft_putchar(str[i]);
		}
		else if (str[i] != '%')
			count = count + ft_putchar(str[i]);
		i++;
	}
	return (count);
}

int				ft_printf(const char *format, ...)
{
	const char	*str;
	va_list		args;
	int			count;

	str = ft_strdup(format);
	count = 0;
	va_start(args, format);
	count = count + parse_str(str, args);
	va_end(args);
	free((char *)str);
	return (count);
}
