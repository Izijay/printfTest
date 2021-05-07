/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 02:31:22 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:18:24 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nb_len(unsigned long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char		*ft_uitoa(unsigned int nbr)
{
	char			*res;
	int				len;
	unsigned long	nb;

	nb = nbr;
	len = ft_nb_len(nb);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len--] = '\0';
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		res[len] = '0';
	while (nb < 0)
	{
		res[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (res);
}

char			*ft_fill_u(t_input *input)
{
	char		*fill;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (input->dot > input->len_variable)
	{
		i = input->dot - input->len_variable;
		input->len_fill = i;
		if (!(fill = (char*)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		ft_bzero(fill, i + 1);
		while (i-- > 0)
			fill[j++] = '0';
		fill[j] = '\0';
		return (fill);
	}
	else
		return (NULL);
}

static void		ft_condition(unsigned int nbr, t_input *input, char *str)
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

void			treat_uint(unsigned int nbr, t_input *input)
{
	char	*str;
	char	*space;
	char	*fill;

	str = ft_uitoa(nbr);
	ft_condition(nbr, input, str);
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
	if (fill);
		free(fill);
}
