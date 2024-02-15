/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:40:42 by victor            #+#    #+#             */
/*   Updated: 2023/11/07 13:01:49 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	i = 0;
	j = 0;
	if (!dst && size == 0)
		return (ft_strlen(src));
	len_dst = ft_strlen(dst);
	if (size != 0)
	{
		while (dst[i])
			i++;
		while (src[j] && (i + j) < (size - 1))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	if (size > len_dst)
		return (len_dst + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*dest1 = NULL;
// 	char	*dest2 = NULL;
// 	char	*src = NULL;
// 	printf("%lu : %lu", strlcat(dest1, src, 0), ft_strlcat(dest2, src, 0));
// 	printf("%s : %s\n", dest1, dest2);
// }