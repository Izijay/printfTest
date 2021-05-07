/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 03:33:18 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:11:48 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_add_fill(t_input *input)
{
	int		i;
	int		j;
	char	*fill;

	i = 0;
	j = 0;
	if (input->dot > input->len_variable - 2)
	{
		i = input->dot - (input->len_variable - 2);
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

static void		ft_condition(unsigned long long nbr, t_input *input, char *str)
{
	if (nbr == '\0' && input->b_dot == 1 && input->dot == 0)
	{
		str[0] = '\0';
		input->len_variable = 2;
	}
	input->len_variable = ((int)ft_strlen(str) + 2);
	if (input->width < input->dot)
		input->width = input->dot + 2;
}

static void		ft_minus(t_input *input, char *str, char *space, char *fill)
{
	ft_buffering(input, "0x", 2);
	if (input->zero == 1)
		ft_buffering(input, space, input->len_space - input->len_fill);
	ft_buffering(input, fill, input->len_fill);
	ft_buffering(input, str, input->len_variable - 2);
}

void			treat_pointer(unsigned long long nbr, t_input *input)
{
	char	*str;
	char	*space;
	char	*fill;

	fill = NULL;
	str = ft_ulltoa_base(nbr);
	ft_condition(nbr, input, str);
	if (input->dot > (int)ft_strlen(str))
		fill = ft_add_fill(input);
	space = treat_width(input);
	if (input->minus == 1)
		ft_minus(input, str, space, fill);
	if (input->zero == 0 && input->len_space > 0)
		ft_buffering(input, space, input->len_space - input->len_fill);
	if (input->minus == 0)
		ft_minus(input, str, space, fill);
	free(str);
	free(space);
	free(fill);
}
