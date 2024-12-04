/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:48:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/08 19:28:59 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conversion(char c, va_list argslist)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_printchar(c);
	else if (c == 'c')
		count += ft_printchar(va_arg(argslist, int));
	else if (c == 's')
		count += ft_printstr(va_arg(argslist, char *));
	else if (c == 'd' || c == 'i')
		count += ft_nbr_base(va_arg(argslist, int), "0123456789", 10);
	else if (c == 'u')
		count += ft_unbr_base(va_arg(argslist, unsigned int), "0123456789", 10);
	else if (c == 'p')
		count += ft_printstr("0x")
			+ ft_unbr_base((unsigned long)va_arg(argslist, void *),
				"0123456789abcdef", 16);
	else if (c == 'x')
		count += ft_unbr_base((unsigned long)va_arg(argslist, unsigned int),
				"0123456789abcdef", 16);
	else if (c == 'X')
		count += ft_unbr_base((unsigned long)va_arg(argslist, unsigned int),
				"0123456789ABCDEF", 16);
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	argslist;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(argslist, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			count += ft_printchar(str[i++]);
		else
		{
			count += ft_conversion(str[++i], argslist);
			i++;
		}
	}
	va_end(argslist);
	return (count);
}
