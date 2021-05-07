/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:16:13 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:06:46 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_input		ft_is_minus(t_input input)
{
	input.minus = 1;
	input.zero = 0;
	return (input);
}

t_input		ft_is_star(t_input input, va_list args)
{
	input.star = 1;
	input.width = va_arg(args, int);
	if (input.width < 0)
	{
		input.minus = 1;
		input.width *= -1;
		input.zero = 0;
	}
	return (input);
}

t_input		ft_is_nbr(char c, char d, t_input input, char *str)
{
	int		tmp;

	tmp = 0;
	if (input.width != 0 && !ft_isdigit(d))
	{
		if (d == '.')
			return (input);
		input.width = 0;
	}
	else if (input.width != 0)
	{
		tmp = input.i;
		while (ft_isdigit(str[input.i]))
			input.i--;
		if (str[input.i] == '.')
		{
			input.i = tmp;
			return (input);
		}
		input.i = tmp;
	}
	(input.star == 1) ? input.width = 0 : input.width;
	input.width = (input.width * 10) + (c - 48);
	return (input);
}
