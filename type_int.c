/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:21:57 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/26 02:54:58 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		input_part_int(char *ret, int tmp_i, t_input input)
{
	int	count;

	count = 0;
	if (tmp_i < 0 && input.dot >= 0)
		ft_putchar('-');
	if (input.dot >= 0)
		count = count + ft_width(input.dot - 1, ft_strlen(ret), 1);
	count = count + putstr_preci(ret, ft_strlen(ret));
	return (count);
}

static int		put_part_int(char *ret, int tmp_i, t_input input)
{
	int	count;

	count = 0;
	if (input.minus == 1)
		count = count + input_part_int(ret, tmp_i, input);
	if (input.dot >= 0 && (size_t)input.dot < ft_strlen(ret))
		input.dot = ft_strlen(ret);
	if (input.dot >= 0)
	{
		input.width -= input.dot;
		count = count + ft_width(input.width, 0, 0);
	}
	else
		count = count + ft_width(input.width, ft_strlen(ret), input.zero);
	if (input.minus == 0)
		count = count + input_part_int(ret, tmp_i, input);
	return (count);
}

int				type_int(int i, t_input input)
{
	char	*ret;
	int		tmp_i;
	int		count;

	tmp_i = i;
	count = 0;
	if (input.dot == 0 && i == 0)
	{
		count = count + ft_width(input.width, 0, 0);
		return (count);
	}
	if (i < 0 && (input.dot >= 0 || input.zero == 1))
	{
		if (input.zero == 1 && input.dot == -1)
			putstr_preci("-", 1);
		i *= -1;
		input.zero = 1;;
		input.width--;
		count++;
	}
	ret = ft_itoa(i);
	count = count + put_part_int(ret, tmp_i, input);
	free (ret);
	return (count);
}
