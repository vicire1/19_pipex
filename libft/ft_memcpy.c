/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:16:08 by victor            #+#    #+#             */
/*   Updated: 2023/11/06 07:56:30 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*pt1;
	unsigned char	*pt2;

	i = 0;
	pt1 = (unsigned char *)dest;
	pt2 = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		pt1[i] = pt2[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[] = "";
	char	src[] = "";

	printf("%s\n%s", ft_memcpy(dest, src, 0), memcpy(dest, src, 0));
} */