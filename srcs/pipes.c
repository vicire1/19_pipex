/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:57:26 by vdecleir          #+#    #+#             */
/*   Updated: 2024/03/11 18:30:37 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_child_exec(t_data *data, char **envp, int i)
{
	close(data->pfd[0]);
	if (data->inv_fd_in == 1 && i == 0)
	{
		close(data->pfd[1]);
		close(data->fd_out);
		exit (0);
	}
	dup2(data->pfd[1], STDOUT_FILENO);
	close(data->pfd[1]);
	if (i == data->nb_cmd_args - 1)
	{
		dup2(data->fd_out, STDOUT_FILENO);
		close(data->fd_out);
	}
	if (!data->cmd_path[i])
	{
		ft_printf(2, "%s: command not found\n", data->cmd[i][0]);
		exit(127);
	}
	execve(data->cmd_path[i], data->cmd[i], envp);
}

static void	ft_child(t_data *data, char **envp, int i)
{
	if (pipe(data->pfd) == -1)
	{
		perror("pipe() error");
		free_exit(data, data->status);
	}
	data->pid = fork();
	if (data->pid == -1)
	{
		perror("fork() error");
		free_exit(data, data->status);
	}
	if (data->pid == 0)
		ft_child_exec(data, envp, i);
}

int	ft_pipex(t_data *data, char **envp)
{
	int	i;

	i = 0;
	dup2(data->fd_in, STDIN_FILENO);
	close(data->fd_in);
	while (i < data->nb_cmd_args)
	{
		ft_child(data, envp, i);
		dup2(data->pfd[0], STDIN_FILENO);
		close(data->pfd[0]);
		close(data->pfd[1]);
		i++;
	}
	while (wait(&data->status) > 0)
		;
	close(data->pfd[0]);
	close(data->pfd[1]);
	return (1);
}
