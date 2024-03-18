/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:12:49 by vdecleir          #+#    #+#             */
/*   Updated: 2024/03/13 17:40:38 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	struct_decla(t_data *data)
{
	data->poss_path = NULL;
	data->cmd = NULL;
	data->cmd_path = NULL;
	data->pfd[0] = -1;
	data->pfd[1] = -1;
	data->pid = -1;
	data->status = 0;
	data->inv_fd_in = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		return (127);
	struct_decla(&data);
	data.fd_in = open(av[1], O_RDONLY);
	if (data.fd_in == -1)
	{
		ft_printf(2, "no such file or directory: %s\n", av[1]);
		data.inv_fd_in = 1;
	}
	data.fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0000644);
	data.nb_cmd_args = ac - 3;
	get_path(&data, envp, av);
	ft_pipex(&data, envp);
	free_exit(&data, data.status);
	return (0);
}
