/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 03:41:22 by mdupuis           #+#    #+#             */
/*   Updated: 2021/01/26 03:49:17 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long			ft_nblen(long nbr)
{
	long	len;
	
	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char				*ft_uitoa(unsigned int nbr)
{
	char	*str;
	long	len;
	long	nb;

	nb = nbr;
	len = ft_nblen(nbr);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}
