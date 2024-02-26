/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:15:03 by victor            #+#    #+#             */
/*   Updated: 2023/11/07 10:25:28 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n)
	{
		str[n - 1] = '\0';
		n--;
	}
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char s[999999999999999] = "Victor";
// 	char t[999999999999999] = "Victor";
// 	ft_bzero(s, 99999999999999);
// 	bzero(t, 99999999999999);
// 	printf("s0 : %c t0 : %c\ns1 : %c t1 : %c", s[0], t[0], s[1], t[1]);
// }