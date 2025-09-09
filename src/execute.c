/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:02:00 by duccello          #+#    #+#             */
/*   Updated: 2025/09/09 14:35:21 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bin.h"
#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "execute.h"
#include "ft_fprintf.h"
#include <signal.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

extern volatile sig_atomic_t	g_flag;

void	execute(t_cmd **cmds, t_data *data)
{
	size_t	i;
	size_t	j;
	int		*pid;

	allocate_pids(data, &pid);
	i = 0;
	j = 0;
	while (i < data->n_cmds)
	{
		if (cmds[i]->argv[0] == NULL)
			;
		else if (cmd_is_built_in(cmds[i]->argv[0], data->built_ins) == true)
			handle_built_in(data, cmds[i]);
		else
			pid[j++] = exec_binary(cmds[i]);
		if (i != 0)
			close(data->pipfd[i - 1][READ]);
		if (i < data->n_cmds - 1)
			close(data->pipfd[i][WRITE]);
		i++;
	}
	pids_and_ret(pid, j, data);
}

void	allocate_pids(t_data *data, int **pid)
{
	if (data->n_cmds > 0)
		*pid = malloc(sizeof(int) * data->n_bins);
	else
		*pid = NULL;
}

uint8_t	get_return_val(int status)
{
	uint8_t	ret_val;

	if ((status & 127) == 0)
		ret_val = (status >> 8);
	else
		ret_val = 128 + (status & 127);
	return (ret_val);
}

void	pids_and_ret(int *pid, int j, t_data *data)
{
	int	i;
	int	status;

	i = 0;
	if (pid != NULL)
	{
		while (i < j)
			waitpid(pid[i++], &status, 0);
		g_flag = 0;
		data->ret_val = get_return_val(status);
		free(pid);
	}
	else
		status = 0;
}
