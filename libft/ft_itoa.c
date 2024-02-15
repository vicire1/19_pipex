/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:06:39 by vdecleir          #+#    #+#             */
/*   Updated: 2023/10/25 12:12:26 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void	int_cpy(int n, int len, char *a)
{
	if (n == 0)
		a[0] = '0';
	if (n < 0)
	{
		a[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		a[len] = (n % 10) + 48;
		n = n / 10;
		len --;
	}
}

char	*ft_itoa(int n)
{
	char	*a;
	int		i;
	int		len;
	char	*tmp;

	len = count_char(n);
	a = malloc(sizeof(char) * (len + 1));
	if (a == NULL)
		return (NULL);
	a[len] = '\0';
	len--;
	if (n == -2147483648)
	{
		tmp = "-2147483648";
		i = 0;
		while (i <= len)
		{
			a[i] = tmp[i];
			i++;
		}
	}
	else
		int_cpy(n, len, a);
	return (a);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
}*/