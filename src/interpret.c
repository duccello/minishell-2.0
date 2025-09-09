/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:07:06 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 18:00:47 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "clean.h"
#include "data.h"
#include "execute.h"
#include "interpret.h"
#include "list.h"
#include "pipes.h"
#include "token.h"
#include "utils.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>

void	interpret(t_data *data, char *s)
{
	if (s == NULL)
		exit(EXIT_SUCCESS);
	if (s[0] == '\0')
		;
	else
	{
		add_history(s);
		if (init(data, s) == 0)
			execute(data->cmds, data);
		destroy(data);
	}
}

int		init(t_data *data, char *s)
{
	data->tokens = tokenize(data, s);
	if (data->tokens == NULL)
		return (1);
	data->cmds = create_cmds(data);
	if (data->cmds == NULL)
		return (1);
	data->n_bins = count_bins(data);
	if (create_pipes(data))
		return (1);
	return (0);
}

void	destroy(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->n_cmds)
		free_cmd(data->cmds[i++]);
	free(data->cmds);
	free_tokens(data->tokens, data);
	free(data->pipfd);
}

