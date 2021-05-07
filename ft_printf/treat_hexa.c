/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:15:03 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:08:34 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_nbrlen(unsigned long nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		len++;
		nbr /= 16;
	}
	return (len);
}

static char			*ft_min_maj(char *hexa, t_input *input)
{
	if (input->type == 'x')
		hexa = "0123456789abcdef";
	else if (input->type == 'X')
		hexa = "0123456789ABCDEF";
	return (hexa);
}

static char			*ft_itoa_hexa(unsigned int nbr, t_input *input)
{
	unsigned long	nb;
	char			*res;
	int				len;
	char			*hexa;

	nb = nbr;
	hexa = NULL;
	len = ft_nbrlen(nb);
	hexa = ft_min_maj(hexa, input);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
	{
		res[len--] = hexa[nb % 16];
		nb /= 16;
	}
	return (res);
}

static void			ft_condition(t_input *input, char *str, unsigned int nbr)
{
	if (nbr == 0 && input->b_dot == 1 && input->dot_exist == 1
					&& input->dot == 0)
		input->len_variable = 0;
	else if (nbr == 0 && input->b_dot == 1 && input->dot_exist == 0
						&& input->dot == 0)
		input->len_variable = 0;
	else
		input->len_variable = (int)ft_strlen(str);
	if (input->dot >= 0 && input->b_dot == 1 && input->dot < input->width
						&& input->zero == 1)
		input->zero = 0;
}

void				treat_hexa(unsigned int nbr, t_input *input)
{
	char	*str;
	char	*space;
	char	*fill;

	space = NULL;
	str = ft_itoa_hexa(nbr, input);
	ft_condition(input, str, nbr);
	space = treat_width(input);
	fill = ft_fill_u(input);
	if (input->minus == 1)
	{
		ft_buffering(input, fill, input->len_fill);
		ft_buffering(input, str, input->len_variable);
	}
	ft_buffering(input, space, input->len_space - input->len_fill);
	if (input->minus == 0)
	{
		ft_buffering(input, fill, input->len_fill);
		ft_buffering(input, str, input->len_variable);
	}
	free(str);
	free(space);
	free(fill);
}
