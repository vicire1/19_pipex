/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:59 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/19 16:29:58 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data {
	int		fd_in;
	int		fd_out;
	int		nb_cmd_args;
	char	**poss_path;
	char	***cmd;
	char	**cmd_path;
}			t_data;

int			get_path(t_data *data, char **envp, char **av);
int			free_exit(t_data *data);
int			test_path(t_data *data, int cmd);

#endif