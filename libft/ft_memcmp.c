/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:54:12 by victor            #+#    #+#             */
/*   Updated: 2023/11/06 07:53:44 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pt1;
	unsigned char	*pt2;

	i = 0;
	pt1 = (unsigned char *)s1;
	pt2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (pt1[i] == pt2[i] && i < n - 1)
		i++;
	return (pt1[i] - pt2[i]);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[] = "AABBA";
	char	s2[] = "AABBA";
	printf("%d : %d", memcmp(s1, s2, 10), ft_memcmp(s1, s2, 10));
}*/