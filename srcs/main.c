/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:12:49 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/14 20:06:09 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    struct_decla(t_data *data)
{
    data->nb_cmd_args = 0;
    printf("il faut encore que tu declares tt\n");
}

int main(int ac, char **av, char **envp)
{
    t_data  data;

    if (ac < 5)
        return (0);
    struct_decla(&data);
    data.nb_cmd_args = ac - 3;
    get_path(&data, envp, av);
    return (1);
}
