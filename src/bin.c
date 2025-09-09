/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:32:36 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/04 13:18:39 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin.h"
#include "clean.h"
#include "libft.h"
#include "list.h"
#include "signals.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
/* 
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
	char	*path;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (c->in_fd != STDIN_FILENO)
	{
		dup2(c->in_fd, STDIN_FILENO);
		close(c->in_fd);
	}
	if (c->out_fd != STDOUT_FILENO)
	{
		dup2(c->out_fd, STDOUT_FILENO);
		close(c->out_fd);
	}
	path = join_path(c->argv[0], c->paths, c);
	execve(path, c->argv, c->envp);
	perror("execve");
	free(path);
	exit(EXIT_FAILURE);
}
 */
/* char	*join_path(char *cmd, char **paths, t_cmd *c)
{
	char	*tmp;
	char	*full;
	int		i;

	i = 0;
	if (cmd == NULL)
	{
		free_cmd(c);
		return (NULL);
	}
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i++], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
	}
	perror("access");
	return (NULL);
} */
