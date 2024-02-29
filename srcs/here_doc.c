/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdecleir <vdecleir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:34:00 by vdecleir          #+#    #+#             */
/*   Updated: 2024/02/29 00:29:47 by vdecleir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void ft_here_doc_child(int *pfd, char *eof)
{
    char    *line;
    int     n;

    close(pfd[0]);
    n = ft_strlen(eof);
    line = get_next_line(0);
    while (line && ft_strncmp(line, eof, n) != 0)
    {
        ft_putstr_fd(line, pfd[1]);
        printf("ok\n");
        free(line);
        line = get_next_line(0);
    }
    printf("ok2\n");
    close(pfd[1]);
    free(line);
    line = NULL;
    exit (0);
}

void ft_here_doc(t_data *data, char *eof)
{
    data->h_doc = 1;
    if(pipe(data->pfd) == -1)
    {
        perror("pipe() error");
        free_exit(data);
    }
    data->pid = fork();
    if(data->pid == -1)
    {
        perror("fork() error");
        free_exit(data);
    }
    if (data->pid == 0)
        ft_here_doc_child(data->pfd, eof);
    else
    {
        waitpid(data->pid, NULL, 0);
        close(data->pfd[1]);
        dup2(data->pfd[0], STDIN_FILENO);
        close(data->pfd[0]);
    }
}
