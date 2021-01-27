/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:22:26 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/19 13:39:40 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		type_percent(t_input input)
{
	int count;

	count = 0;
	if (input.minus == 1)
		count = count = putstr_preci("%", 1);
	count = count + ft_width(input.width, 1, input.zero);
	if (input.minus == 0)
		count = count + putstr_preci("%", 1);
	return (count);
}
