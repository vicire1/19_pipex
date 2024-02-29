/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:01:28 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/28 22:10:55 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char			*get_next_line(int fd);
char			*ft_strjoin_gnl(char *s1, char *s2, int i, int j);
unsigned int	ft_strlen_gnl(const char *s);
char			*ft_strchr_gnl(const char *s, int c);
char			*ft_substr_gnl(char *s, unsigned int start);
void			*ft_calloc_gnl(size_t nmemb, size_t size);

#endif
