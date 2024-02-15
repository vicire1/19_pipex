/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:15:29 by vdecleir          #+#    #+#             */
/*   Updated: 2023/11/21 12:37:29 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		printf_putstr("-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		printf_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		printf_putchar(nb + 48);
	}
}

int	count_signed(int nb)
{
	int	len;

	len = 0;
	ft_putnbr(nb);
	if (nb == -2147483648)
		return (11);
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
