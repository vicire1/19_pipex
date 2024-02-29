/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:12:49 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/29 00:53:58 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	struct_decla(t_data *data, int ac, char **av)
{
	data->fd_out = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0000644);
	data->poss_path = NULL;
	data->cmd = NULL;
	data->cmd_path = NULL;
	data->h_doc = 0;
}

void	print_struct(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n-----------------\n");
	printf("FD's:             |");
	printf("\n-----------------\n");
	printf("fd_in: %i\nfd_out: %i\n", data->fd_in, data->fd_out);
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

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (0);
	struct_decla(&data, ac, av);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			free_exit(&data);
		ft_here_doc(&data, av[2]);
	}
	else
	{
		data.fd_in = open(av[1], O_RDONLY);
		if (data.fd_in == -1)
		{
			perror("open() error");
			free_exit(&data);
		}
	}
	data.nb_cmd_args = ac - 3 - data.h_doc;
	get_path(&data, envp, av);
	//print_struct(&data);             // A RETIRER !!!
	ft_pipex(&data, envp);
	free_exit(&data);
	return (1);
}
