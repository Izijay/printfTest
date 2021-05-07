/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 03:51:18 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/07 13:16:27 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nblen(unsigned long long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (0);
	while (nbr)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

char	*ft_ulltoa_base(unsigned long long nbr)
{
	char	*hexa;
	int		len;
	char	*ret;

	len = ft_nblen(nbr);
	hexa = "0123456789abcdef";
	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	len--;
	if (nbr == 0)
		ret[0] = '0';
	while (nbr != 0)
	{
		ret[len--] = hexa[nbr % 16];
		nbr /= 16;
	}
	return (ret);
}
