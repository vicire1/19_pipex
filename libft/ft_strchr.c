/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:16:40 by victor            #+#    #+#             */
/*   Updated: 2023/11/06 07:53:10 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (&str[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s[] = "salut";
	printf("%s\n%s", ft_strchr(s, 's'), strchr(s, 's'));
}*/
