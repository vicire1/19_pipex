/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:41:07 by victor            #+#    #+#             */
/*   Updated: 2023/11/06 07:52:27 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	dest1[7] = "Vic";
	char	dest2[7] = "Vic";
	char	src[] = "tor";
	strlcpy(dest1, src, 4);
	ft_strlcpy(dest2, src, 4);
	printf("%s : %s\n", dest1, dest2);
	printf("%lu : %lu", strlcpy(dest1, src, 4), ft_strlcpy(dest2, src, 4));
}*/