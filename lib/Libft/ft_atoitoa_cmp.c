/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoitoa_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:59:24 by jose-gon          #+#    #+#             */
/*   Updated: 2024/12/16 19:13:57 by jose-gon         ###   ########.fr       */
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
		return(-1);
	if (!ft_strcmp(s1, s2))
	{
		free(s2);
		return(0);
	}
	free(s2);
	return(1);
}
