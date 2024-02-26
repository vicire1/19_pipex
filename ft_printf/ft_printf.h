/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:28:58 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/14 13:33:01 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	printf_putstr(char *str);
int	count_unsigned(unsigned int nb, char *str);
int	ft_strlen2(char *str);
int	printf_putchar(int c);
int	count_signed(int nb);
int	count_adress(void const *adr, char *str);

#endif