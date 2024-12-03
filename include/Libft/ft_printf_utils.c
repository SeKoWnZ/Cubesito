/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:09:23 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/08 19:28:48 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	return (write(1, &c, sizeof(char)));
}

int	ft_printstr(char *c)
{
	int	count;

	count = 0;
	if (!c)
		return (ft_printstr("(null)"));
	while (c[count])
		count += ft_printchar(c[count]);
	return (count);
}

int	ft_nbr_base(int n, char *b, int c)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (n < 0)
	{
		n = -n;
		count += ft_printchar('-');
		count += ft_nbr_base(n, b, c);
	}
	else if (n >= c)
	{
		ft_nbr_base(n / c, b, c);
		count += ft_printchar(b[n % c]);
	}
	else
		count += ft_printchar(b[n]);
	return (count);
}

int	ft_unbr_base(unsigned long n, char *b, int c)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)c)
	{
		count += ft_unbr_base(n / c, b, c);
		count += ft_printchar(b[n % c]);
	}
	else
		count += ft_printchar(b[n]);
	return (count);
}
