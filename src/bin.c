/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:32:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/10 11:55:55 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin.h"
#include "clean.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include "signals.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define CMD_NOT_FOUND 127

int	exec_binary(t_cmd *c)
{
	int		pid;

	pid = fork();
	if (pid == 0)
		run_child_process(c);
	else
		g_flag = 1;
	return (pid);
}

void	run_child_process(t_cmd *c)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (c->in_fd != STDIN_FILENO)
		dup2(c->in_fd, STDIN_FILENO);
	if (c->out_fd != STDOUT_FILENO)
		dup2(c->out_fd, STDOUT_FILENO);
	c->path = create_path(c);
	if (c->path == NULL)
	{
		c->data->ret_val = CMD_NOT_FOUND;
		exit(c->data->ret_val);
	}
	if (access(c->path, X_OK) == 0)
		execve(c->path, c->argv, c->envp);
}

