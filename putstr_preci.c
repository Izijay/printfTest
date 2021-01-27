/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_preci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:40:14 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/19 13:41:59 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			putstr_preci(char *str, int prec)
{
	int	count;

	count = 0;
	while (str[count] && count < prec)
		ft_putchar(str[count++]);
	return (count);
}
