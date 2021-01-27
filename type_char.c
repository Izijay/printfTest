/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 01:16:17 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/26 12:17:53 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			type_char(char c, t_input input)
{
	int	count;

	count = 0;
	if (input.minus == 1)
		ft_putchar(c);
	count = ft_width(input.width, 1, 0);
	if (input.minus == 0)
		ft_putchar(c);
	return (count + 1);
}
