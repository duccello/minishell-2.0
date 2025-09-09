/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:07:06 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 10:21:07 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "cmds.h"
#include "interpret.h"
#include "list.h"
#include "built_in.h"
#include "token.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

void	interpret(t_data *data, char *s)
{
	if (s == NULL)
		exit (EXIT_SUCCESS);
	if (s[0] == '\0')
		;
	else
	{
		add_history(s);
		init(data, s);
	}
}

void	init(t_data *data, char *s)
{
	data->tokens = tokenize(data, s);
	if (data->tokens == NULL)
		return ;
	data->cmds = create_cmds(data);
	for (size_t i = 0; i < data->n_cmds; i++)
		for (size_t j = 0; data->cmds[i]->argv[j] != NULL; j++)
			printf("cmd[%zu]: argv[%zu]: %s\n", i, j, data->cmds[i]->argv[j]);
}
