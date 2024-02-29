/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:01:31 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/28 22:19:20 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	ft_strlen_gnl(const char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int i, int j)
{
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!join)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join [i + j] = '\0';
	free(s1);
	s1 = NULL;
	return (join);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
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

char	*ft_substr_gnl(char *s, unsigned int start)
{
	unsigned int	i;
	char			*sub;

	i = 0;
	if (!s)
		return (0);
	while (start + i < ft_strlen_gnl(s))
		i++;
	sub = malloc(sizeof(char) * (i + 1));
	if (!sub)
	{
		free(s);
		s = NULL;
		return (NULL);
	}
	i = 0;
	while (start + i < ft_strlen_gnl(s))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	free(s);
	s = NULL;
	return (sub);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*array;
	size_t	bytes;

	bytes = nmemb * size;
	array = malloc(bytes);
	if (array == NULL)
		return (NULL);
	while (bytes)
	{
		array[bytes - 1] = '\0';
		bytes--;
	}
	return (array);
}
