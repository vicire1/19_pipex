/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:37:50 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/14 13:32:40 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_adress(unsigned long int adress, char *str)
{
	unsigned long int	base;

	base = ft_strlen2(str);
	if (adress < 0)
	{
		printf_putchar('-');
		adress = -adress;
	}
	if (adress >= base)
	{
		print_adress(adress / base, str);
		print_adress(adress % base, str);
	}
	if (adress < base)
		printf_putchar(str[adress]);
}

int	count_adress(void const *adr, char *str)
{
	unsigned long int	adress;
	int					count;
	int					base;

	if (!str)
		return (0);
	adress = (unsigned long int)adr;
	base = ft_strlen2(str);
	printf_putstr("0x");
	count = 2;
	print_adress(adress, str);
	if (adress == 0)
		return (3);
	while (adress > 0)
	{
		adress = adress / base;
		count++;
	}
	return (count);
}
