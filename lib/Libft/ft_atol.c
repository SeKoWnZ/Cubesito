/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 01:08:30 by jose-gon          #+#    #+#             */
/*   Updated: 2024/08/29 01:08:34 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	final;
	long	i;
	long	negative;

	i = 0;
	negative = 1;
	final = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		final = (str[i] - '0') + (final * 10);
		i++;
	}
	return (final * negative);
}
