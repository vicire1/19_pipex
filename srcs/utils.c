/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:04:54 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/18 21:57:24 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void    free_str_tab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        free(tab[i]);
        tab[i] = NULL;
    }
    tab = NULL;
}

int free_exit(t_data *data)
{
    int i;
    
    if (data->poss_path)
        free_str_tab(data->poss_path);
    i = 0;
    if (data->cmd)
    {
        while (data->cmd[i])
        {
            free_str_tab(data->cmd[i]);
            i++;
        }
        free(data->cmd);
        data->cmd = NULL;
    }
    if (data->cmd_path)
        free_str_tab(data->cmd_path);
    exit (0);
}

void    test_path(t_data *data, int cmd)
{
    int i;
    char    *temp;
    
    i = 0;
    data->cmd_path[cmd] = NULL;
    while (data->poss_path[i])
    {
        temp = ft_strjoin(data->poss_path[i], data->cmd[cmd][0]);
        if (access(temp, X_OK) == 0)
        {
            data->cmd_path[cmd] = temp;
            break;
        }
        free(temp);
        i++;
    }
}
