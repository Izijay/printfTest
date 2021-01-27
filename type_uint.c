/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_uint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 02:58:37 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/26 03:17:36 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		input_part_uint(char *str_uint, t_input input)
{
	int	count;

	count = 0;
	if (input.dot >= 0)
		count = count + ft_width(input.dot - 1, ft_strlen(str_uint) - 1, 1);
	count = count + putstr_preci(str_uint, ft_strlen(str_uint));
	return (count);
}

static int		put_part_uint(char *str_uint, t_input input)
{
	int	count;

	count = 0;
	if (input.minus == 1)
		count = count + input_part_uint(str_uint, input);
	if (input.dot >= 0 && (size_t)input.dot < ft_strlen(str_uint))
		input.dot = ft_strlen(str_uint);
	if (input.dot >= 0)
	{
		input.width -= input.dot;
		count = count + ft_width(input.width, 0, 0);
	}
	else
		count = count + ft_width(input.width, ft_strlen(str_uint), input.zero);
	if (input.minus == 0)
		count = count + input_part_uint(str_uint, input);
	return (count);
}

int				type_uint(unsigned int uint, t_input input)
{
	char	*str_uint;
	int		count;

	count = 0;
	uint = (unsigned int)(4294967295 + 1 + uint);
	if (input.dot == 0 && uint == 0)
	{
		count = count + ft_width(input.width, 0, 0);
		return (count);
	}
	str_uint = ft_uitoa(uint);
	count = count + put_part_uint(str_uint, input);
	free(str_uint);
	return (count);
}
