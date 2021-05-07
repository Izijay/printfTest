/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 02:04:49 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:05:44 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_chartostr(char c)
{
	char	*ret;
	
	ret = ft_calloc(2, sizeof(char));
	ret[0] = c;
	ret[1] = '\0';
	return (ret);
}

void		treat_char(char c, t_input *input)
{
	char	*str;
	char	*space;

	str = NULL;
	str = ft_chartostr(c);
	input->len_variable = 1;
	space = treat_width(input);
	if (input->minus == 1)
		ft_buffering(input, str, input->len_variable);
	ft_buffering(input, space, input->len_space);
	if (input->minus == 0)
		ft_buffering(input, str, input->len_variable);
	free(str);
	free(space);
}
