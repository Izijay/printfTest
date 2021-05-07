/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:15:00 by mdupuis           #+#    #+#             */
/*   Updated: 2021/04/27 17:06:59 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_condition(t_input *input)
{
	if (input->dot > 0 && input->type == 's')
		input->len_variable = input->dot;
	if (input->type == 'p' && input->b_dot == 1 && input->dot >= 0)
		inpot->zero = 0;
	else if (input->type == 'd' && input->b_dot == 1 && input->dot >= 0)
		input->zero = 0;
	else if (input->type == 'i' && input->b_dot == 1 && input->dot >= 0)
		input->zero = 0;
}

char				*treat_width(t_input *input)
{
	char	*space;
	int		i;

	i = 0;
	ft_condition(input);
	if (input->width < input->len_variable)
		return (NULL);
	if (!(space = ft_calloc((input->width - input->len_variable + 1),
				sizeof(char))))
		return (NULL);
	while (i < input->width - input->len_variable)
	{
		if (input->zero == 1)
			space[i] = '0';
		else if (input->zero == 0)
			space[i] = ' ';
		i++;
	}
	space[i] = '\0';
	input->len_space = i;
	return (space);
}
