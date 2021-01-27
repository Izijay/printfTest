/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:48:12 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/19 15:01:07 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_dot(const char *str, int start, t_input *input, va_list args)
{
	int	i;

	i = start;
	i++;
	if (str[i] == '*')
	{
		input->dot = va_arg(args, int);
		i++;
	}
	else
	{
		input->dot = 0;
		while (ft_isdigit(str[i]))
			input->dot = (input->dot * 10) + (str[i++] - 48);
	}
	return (i);
}

t_input		flag_minus(t_input input)
{
	input.minus = 1;
	input.zero = 0;
	return (input);
}

t_input		flag_width(va_list args, t_input input)
{
	input.asterisk = 1;
	input.width = va_arg(args, int);
	if (input.width < 0)
	{
		input.minus = 1;
		input.width *= -1;
	}
	return (input);
}

t_input		flag_digit(char c, t_input input)
{
	if (input.asterisk == 1)
		input.width = 0;
	input.width = (input.width * 10) + (c - 48);
	return (input);
}
