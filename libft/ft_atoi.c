/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:14:40 by victor            #+#    #+#             */
/*   Updated: 2023/11/06 08:03:21 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	excpetion(unsigned long long nb, int sign)
{
	if (nb > 9223372036854775807)
	{
		if (sign < 0)
			return (0);
		if (sign > 0)
			return (-1);
	}
	return (nb);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && nb < 9223372036854775807)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = excpetion(nb, sign);
	return (nb * sign);
}
/*
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", ft_atoi("-922337203685477580855555"));
	printf("%d\n", atoi("-922337203685477580855555"));
}*/
