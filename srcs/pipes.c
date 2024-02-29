/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:57:26 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/29 00:35:42 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void ft_child_exec(t_data *data, char **envp, int i)
{
    if (pipe(data->pfd) == -1)
    {
        perror("pipe() error");
        free_exit(data);
    }
    data->pid = fork();
    if (data->pid == -1)
    {
        perror("fork() error");
        free_exit(data);
    }
    if (data->pid == 0)
    {
        dup2(data->pfd[1], STDOUT_FILENO);
        close(data->pfd[0]);
        close(data->pfd[1]);
        if (i == data->nb_cmd_args - 1)
            dup2(data->fd_out, STDOUT_FILENO);
        execve(data->cmd_path[i], data->cmd[i], envp);
    }
    else
        waitpid(data->pid, &data->status, 0);
}

int ft_pipex(t_data *data, char **envp)
{
    int i;

    i = 0;
    dup2(data->fd_in, STDIN_FILENO);
    while (i < data->nb_cmd_args)
    {
        ft_child_exec(data, envp, i);
        dup2(data->pfd[0], STDIN_FILENO);
        dup2(data->prev_pipe, data->pfd[0]);
        close(data->pfd[0]);
        close(data->pfd[1]);
        i++;
    }
    close(data->prev_pipe);
    close(data->pfd[0]);
    close(data->pfd[1]);
    return (1);
}
