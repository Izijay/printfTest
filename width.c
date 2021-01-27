/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:35:20 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/19 13:39:22 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_width(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width = width = 1;
		count ++;
	}
	return (count);
}
