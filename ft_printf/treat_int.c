/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:07:38 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:10:51 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_fill(t_input *input, int nbr)
{
	char	*fill;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (input->dot > input->len_variable - 1)
	{
		if (nbr < 0)
			i = input->dot - input->len_variable + 1;
		else
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

static void		ft_condition(int nbr, t_input *input, char *str)
{
	if (nbr == 0 && input->b_dot == 1 && input->dot == 0
				&& input->dot_exist == 0)
		input->len_variable = 0;
	else if (nbr < 0)
		input->len_variable = (int)ft_strlen(str) + 1;
	else if (nbr > 0)
		input->len_variable = (int)ft_strlen(str);
	else if (nbr == 0 && input->b_dot == 0)
		input->len_variable = 1;
	else if (nbr == 0 && input->b_dot == 1 && input->dot < 0
				&& input->dot_exist == 1)
		input->len_variable = 1;
	else if (nbr == 0 && input->dot_exist == 1 && input->dot > 0)
		input->len_variable = 1;
	if (input->width < input->dot)
	{
		if (nbr < 0)
			input->width = input->dot + 1;
		else if (nbr > 0)
			input->width = input->dot;
	}
}

static void		treat_min_first(int nbr, t_input *input, char *space)
{
	if (nbr < 0)
	{
		ft_buffering(input, "-", 1);
		if (input->zero == 1)
			ft_buffering(input, space, input->len_space - input->len_fill);
	}
}

static void		treat_min_after(int nbr, t_input *input, char *str, char *fill)
{
	ft_buffering(input, fill, input->len_fill);
	if (nbr < 0)
		ft_buffering(input, str, input->len_variable - 1);
	else
		ft_buffering(input, str, input->len_variable);
}

void			treat_int(int nbr, t_input *input)
{
	char	*str;
	char	*space;
	char	*fill;

	fill = NULL;
	str = ft_itoa(nbr);
	ft_condition(nbr, input, str);
	if (input->dot > (int)ft_strlen(str))
		fill = ft_fill(input, nbr);
	space = treat_width(input);
	if (input->minus == 1)
	{
		treat_min_first(nbr, input, space);
		treat_min_after(nbr, input, str, fill);
	}
	if ((input->zero == 0) || (input->zero == 1 && nbr >= 0))
		ft_buffering(input, space, input->len_space - input->len_fill);
	if (input->minus == 0)
	{
		treat_min_first(nbr, input, space);
		treat_min_after(nbr, input, str, fill);
	}
	free(fill);
	free(str);
	free(space);
}
