/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:12:49 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/18 22:32:28 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    struct_decla(t_data *data, int ac)
{
    data->nb_cmd_args = ac - 3;
    data->poss_path = NULL;
    data->cmd = NULL;
    data->cmd_path = NULL;
}

void    print_struct(t_data *data)
{
    int i = 0;
    int j = 0;
    printf("\n-------------------------\n");
    printf("Number of command arg: %i |", data->nb_cmd_args);
    printf("\n-------------------------\n");
    printf("\n-----------------\n");
    printf("Possible Paths:  |");
    printf("\n-----------------\n");
    while (data->poss_path[i])
    {
        printf("%s\n", data->poss_path[i]);
        i++;
    }
    printf("\n-----------------\n");
    printf("Arguments:       |");
    printf("\n-----------------\n");
    i = 0;
    while (data->cmd[i])
    {
        j = 0;
        printf("\n---command---\n");
        printf("%s\n", data->cmd[i][j]);
        j++;
        printf("\n---param---\n");
        while (data->cmd[i][j])
        {
            printf("%s\n", data->cmd[i][j]);
            j++;
        }
        printf("\n---abs path---\n");
        printf("%s\n\n\n", data->cmd_path[i]);
        i++;
    }
}

int main(int ac, char **av, char **envp)
{
    t_data  data;

    if (ac < 5)
        return (0);
    struct_decla(&data, ac);
    get_path(&data, envp, av);
    print_struct(&data);                                        // A RETIRER !!!
    free_exit(&data);
    return (1);
}
