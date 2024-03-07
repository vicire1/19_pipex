/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:12:49 by vdecleir          #+#    #+#             */
/*   Updated: 2024/03/07 19:01:33 by vdecleir         ###   ########.fr       */
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
	data->status = 1;
	data->h_doc = 0;
	data->inv_fd_in = 0;
}

static void	open_in(t_data *data, char *infile, char *outfile)
{
	data->fd_in = open(infile, O_RDONLY);
	if (data->fd_in == -1)
	{
		ft_printf(2, "no such file or directory: %s\n", infile);
		data->inv_fd_in = 1;
	}
	data->fd_out = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0000644);
}
int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (127);
	struct_decla(&data);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			free_exit(&data, data.status);
		ft_here_doc(&data, av[2], av[ac - 1]);
	}
	else
		open_in(&data, av[1], av[ac - 1]);
	data.nb_cmd_args = ac - 3 - data.h_doc;
	get_path(&data, envp, av);
	ft_pipex(&data, envp);
	free_exit(&data, 0);
	return (1);
}
