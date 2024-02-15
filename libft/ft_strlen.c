/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:16:46 by victor            #+#    #+#             */
/*   Updated: 2023/11/06 10:51:58 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*#include <stdio.h>
#include <string.h>

int	main()
{
	char str[20] = "salut comment ca va";
	printf("%lu\n", ft_strlen(str));
	printf("%lu", strlen(str));
}*/
