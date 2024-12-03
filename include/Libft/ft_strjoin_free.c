/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:48:51 by jose-gon          #+#    #+#             */
/*   Updated: 2024/05/27 14:03:07 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int flag)
{
	char	*s3;

	if (!s1 && !s2)
		return (0);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (0);
	ft_memcpy(s3, s1, ft_strlen(s1));
	ft_memcpy(s3 + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	if (flag == 2)
	{
		free(s1);
		free(s2);
	}
	if (flag == 1)
		free(s1);
	return (s3);
}
