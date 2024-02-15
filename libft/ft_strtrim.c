/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 14:19:00 by victor            #+#    #+#             */
/*   Updated: 2023/10/25 12:14:33 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	nb_set(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (check_set(s1[i], set) == 1)
	{
		i++;
		count++;
	}
	if (!(s1[i]))
		return (count);
	while (s1[i])
		i++;
	while (check_set(s1[i - 1], set) == 1)
	{
		i--;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	new = malloc(sizeof(char) * (len - nb_set(s1, set) + 1));
	if (new == NULL)
		return (NULL);
	while (check_set(s1[i], set) == 1)
		i++;
	while (s1[j + nb_set(s1, set)])
	{
		new[j] = (char)s1[i + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

/*
#include <stdio.h>
int	main(void)
{
	char *s1 = "            ";
	char *set = " ";
	printf("%s", ft_strtrim(s1, set));
}*/