/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:04:54 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/19 17:45:17 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_str_tab(char **tab, unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb == 0)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
	}
	if (nb > 0)
	{
		while (i < nb)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
	}
	free(tab);
	tab = NULL;
}

int	free_exit(t_data *data)
{
	int	i;

	if (data->poss_path)
		free_str_tab(data->poss_path, 0);
	i = 0;
	if (data->cmd)
	{
		while (i < data->nb_cmd_args)
		{
			free_str_tab(data->cmd[i], 0);
			i++;
		}
		free(data->cmd);
		data->cmd = NULL;
	}
	if (data->cmd_path)
		free_str_tab(data->cmd_path, data->nb_cmd_args);
	exit(0);
}

int	test_path(t_data *data, int cmd)
{
	int		i;
	char	*temp;

	i = 0;
	data->cmd_path[cmd] = NULL;
	while (data->poss_path[i])
	{
		temp = ft_strjoin(data->poss_path[i], data->cmd[cmd][0]);
		if (access(temp, X_OK) == 0)
		{
			data->cmd_path[cmd] = temp;
			return (1);
		}
		free(temp);
		temp = NULL;
		i++;
	}
	return (0);
}
