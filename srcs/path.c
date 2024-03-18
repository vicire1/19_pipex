/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:14:57 by vdecleir          #+#    #+#             */
/*   Updated: 2024/03/15 12:33:51 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	***get_cmds(t_data *data, char **av)
{
	int	arg;
	int	i;

	arg = 2;
	i = 0;
	data->cmd = malloc(sizeof(char **) * (data->nb_cmd_args + 1));
	if (!data->cmd)
		free_exit(data, data->status);
	while (i < data->nb_cmd_args)
	{
		data->cmd[i] = ft_split(av[arg], ' ');
		if (!data->cmd[i])
			free_exit(data, data->status);
		i++;
		arg++;
	}
	data->cmd[i] = NULL;
	return (data->cmd);
}

static char	**get_abs_path(t_data *data, char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			data->poss_path = ft_split(&envp[i][5], ':');
			if (!data->poss_path)
				free_exit(data, data->status);
			return (data->poss_path);
		}
		i++;
	}
	return (NULL);
}

static char	**put_slash(t_data *data)
{
	int		i;
	char	*temp;

	i = 0;
	while (data->poss_path[i])
	{
		temp = ft_strjoin(data->poss_path[i], "/");
		free(data->poss_path[i]);
		data->poss_path[i] = temp;
		i++;
	}
	return (data->poss_path);
}

static char	**find_good_path(t_data *data)
{
	int	i;

	i = 0;
	data->cmd_path = malloc(sizeof(char *) * (data->nb_cmd_args + 1));
	if (!data->cmd_path)
		free_exit(data, data->status);
	while (data->cmd[i])
	{
		data->cmd_path[i] = NULL;
		if (access(data->cmd[i][0], X_OK) == 0)
			data->cmd_path[i] = ft_strdup(data->cmd[i][0]);
		else if (data->poss_path)
			test_path(data, i);
		i++;
	}
	data->cmd_path[i] = NULL;
	return (data->cmd_path);
}

int	get_path(t_data *data, char **envp, char **av)
{
	get_cmds(data, av);
	get_abs_path(data, envp);
	if (data->poss_path)
		put_slash(data);
	find_good_path(data);
	return (1);
}
