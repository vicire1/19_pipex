/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:32:15 by vdecleir          #+#    #+#             */
/*   Updated: 2023/11/07 10:39:01 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	bytes;

	bytes = nmemb * size;
	array = malloc(bytes);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, bytes);
	return (array);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%lu\n", sizeof(size_t));
// 	printf("%p\n", ft_calloc(0, 0));
// 	printf("%p", calloc(0, 0));
// }
