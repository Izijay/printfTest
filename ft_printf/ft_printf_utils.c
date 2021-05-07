/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 01:53:33 by mdupuis           #+#    #+#             */
/*   Updated: 2021/05/03 01:04:17 by mdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_check_flags(char c)
{
	return (c == '.' || c == '0' || c == '-' ||  c == '-' || c == '*');
}

int			ft_check_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
					|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

void		ft_display(t_input *input)
{
	write(1, input->buffer, input->index);
	input->index = 0;
}

void		ft_buffering(t_input *input, char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		input->buffer[input->index] = str[i];
		input->index++;
		if (input->index == 1024)
			ft_display(input);
		i++;
	}
	if (len < 0)
		return ;
	input->ret_len += len;
}

void		ft_noflags(t_input *input, char *str)
{
	int		len;

	len = 0;
	while (str[input->i] && str[input->i] != '%')
	{
		input->buffer[input->index] = str[input->i];
		input->index++;
		len++;
		if (input->index == 1024)
			ft_display(input);
		input->i++;
	}
	input->ret_len += len;
	input->i--;
}
