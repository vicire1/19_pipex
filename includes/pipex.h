/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:47:59 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/18 21:39:31 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_data {
    int     nb_cmd_args;
    char    **poss_path;
    char    ***cmd;
    char    **cmd_path;
}           t_data;

int get_path(t_data *data, char **envp, char **av);
int free_exit(t_data *data);
void    test_path(t_data *data, int cmd);

#endif