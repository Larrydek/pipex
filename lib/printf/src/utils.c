/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-clee <jde-clee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:12:27 by jde-clee          #+#    #+#             */
/*   Updated: 2024/01/27 21:55:55 by jde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_string(char *s, int *len)
{
	if (!s)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		(*len)++;
	}
}

void	ft_float(int n, int *len)
{
	*len += ft_int_len(n);
	ft_putnbr(n);
}
