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

#include "built_in.h"
#include "cmds.h"
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
		init(data, s);
		execute(data->cmds, data);
	}
}

void	init(t_data *data, char *s)
{
	data->tokens = tokenize(data, s);
	if (data->tokens == NULL)
		return ;
	data->cmds = create_cmds(data);
	data->n_bins = count_bins(data);
	create_pipes(data);
}
