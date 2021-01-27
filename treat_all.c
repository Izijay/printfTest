/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:02:47 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/27 14:18:18 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
					|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		check_flags(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0')
					|| (c == '.') || (c == '*'));
}

int		treat_all(int c, t_input input, va_list args)
{
	int		count;

	count = 0;
	if (c == 'c')
		count = type_char(va_arg(args, int), input);
	else if (c == 's')
		count = type_string(va_arg(args, char *), input);
//	else if (c == 'p')
//		count = type_pointer(va_arg(args, unsigned long long), input);
	else if (c == 'd' || c == 'i')
		count = type_int(va_arg(args, int), input);
	else if (c == 'u')
		count += type_uint((unsigned int)va_arg(args, unsigned int), input);
//	else if (c == 'x')
//		count += type_hexa(va_arg(args, unsigned int), 1, input);
//	else if (c == 'X')
//		count += type_hexa(va_arg(args, unsigned int), 0, input);
	else if (c == '%')
		count += type_percent(input);
	return (count);
}
