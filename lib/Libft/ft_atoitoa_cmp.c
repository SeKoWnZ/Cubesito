/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoitoa_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarajime <sarajime@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:59:24 by jose-gon          #+#    #+#             */
/*   Updated: 2025/02/20 17:22:47 by sarajime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoitoa_cmp(char *s1)
{
	int		n;
	char	*s2;

	n = ft_atoi(s1);
	s2 = ft_itoa(n);
	if (!s2)
		return (-1);
	if (!ft_strcmp(s1, s2))
	{
		free(s2);
		return (0);
	}
	free(s2);
	return (1);
}
