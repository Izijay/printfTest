/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:00:16 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:12:35 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_minus(t_input *input, char *str, char *space)
{
	space = treat_width(input);
	if (input->minus == 1)
	{
		if (input->dot > 0)
			ft_buffering(input, str, input->dot);
		else
			ft_buffering(input, str, input->len_variable);
	}
	ft_buffering(input, space, input->len_space);
	if (input->minus == 0)
	{
		if (input->dot > 0)
			ft_buffering(input, str, input->dot);
		else
			ft_buffering(input, str, input->len_variable);
	}
	free(space);
}

void				treat_string(char *str, t_input *input)
{
	char	*space;

	space = NULL;
	if (!str)
		str = "(null)";
	if (input->b_dot == 1 && input->dot == 0)
	{
		space = treat_width(input);
		ft_buffering(input, space, input->len_space);
		free(space);
		return ;
	}
	input->len_variable = (int)ft_strlen(str);
	if (input->dot > 0 && input->dot > input->len_variable)
		input->dot = input->len_variable;
	ft_minus(input, str, space);
}
