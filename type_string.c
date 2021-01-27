/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:43:26 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/19 13:55:58 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_part_int(char *str, t_input input)
{
	int	count;

	count = 0;
	if (input.dot >= 0)
	{
		count = count + ft_width(input.dot, ft_strlen(str), 0);
		count = count + putstr_preci(str, ft_strlen(str));
	}
	else
	{
		count = count + putstr_preci(str, ft_strlen(str));
	}
	return (count);
}

int			type_string(char *str, t_input input)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	if (input.dot >= 0 && (size_t)input.dot > ft_strlen(str))
		input.dot = ft_strlen(str);
	if (input.minus == 1)
		count = count + put_part_int(str, input);
	if (input.dot >= 0)
		count = count + ft_width(input.width, input.dot, 0);
	else
		count = count + ft_width(input.width, ft_strlen(str), 0);
	if (input.minus == 0)
		count = count + put_part_int(str, input);
	return (count);
}
