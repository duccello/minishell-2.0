/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:53:24 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 18:16:49 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "token.h"
#include <stdio.h>
#include <stdlib.h>

t_cmd	**create_cmds(t_data *data)
{
	t_cmd	**cmds;
	size_t	i;

	data->n_cmds = count_cmds(data->tokens, data);
	cmds = malloc(sizeof(t_cmd *) * data->n_cmds);
	if (cmds == NULL)
		return (NULL);
	i = 0;
	while (i < data->n_cmds)
		cmds[i++] = create_cmd(data->tokens, data);
	return (cmds);
}

size_t	count_cmds(t_tok **tokens, t_data *data)
{
	size_t	counter;
	size_t	i;

	counter = 1;
	i = 0;
	while (i < data->n_tokens)
	{
		if (tokens[i]->pipe == true)
			counter++;
		i++;
	}
	return (counter);
}

t_cmd	*create_cmd(t_tok **tokens, t_data *data)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	cmd->data = data;
	cmd->argv = create_argv(tokens, data);
	populate_cmd(cmd, tokens);
	return (cmd);
}

char	**create_argv(t_tok **tokens, t_data *data)
{
	char			**argv;
	size_t			counter;
	static size_t	i;

	counter = 0;
	if (tokens[i]->pipe == true)
		i++;
	while (i < data->n_tokens && tokens[i]->pipe == false)
	{
		if (tokens[i]->string == true)
			counter++;
		i++;
	}
	printf("%zu\n", counter);
	argv = malloc(sizeof(char *) * (counter + 1));
	if (argv == NULL)
		return (NULL);
	return (argv);
}

void	populate_cmd(t_cmd *cmd, t_tok **tokens)
{
	size_t i;
	static size_t index;

	if (tokens[index]->pipe == true)
		(index)++;
	i = 0;
	while (index < cmd->data->n_tokens && tokens[index]->pipe == false)
	{
		if (tokens[index]->input_file == true)
			cmd->in_file = tokens[index]->s;
		else if (tokens[index]->output_file == true)
			cmd->out_file = tokens[index]->s;
		else if (tokens[index]->append_file == true)
			cmd->append_file = tokens[index]->s;
		else if (tokens[index]->heredoc_delimiter == true)
			cmd->delimiter = tokens[index]->s;
		else if (tokens[index]->string == true)
			cmd->argv[i++] = tokens[index]->s;
		(index)++;
	}
	cmd->argv[i] = NULL;
}