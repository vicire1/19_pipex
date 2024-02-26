/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_ft_lstclear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:21:26 by vdecleir          #+#    #+#             */
/*   Updated: 2023/11/07 12:48:49 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tofree;
	t_list	*current;

	if (*lst == NULL || lst == NULL || !del)
		return ;
	current = *lst;
	while (current)
	{
		tofree = current;
		current = current->next;
		ft_lstdelone(tofree, del);
	}
	*lst = NULL;
}
