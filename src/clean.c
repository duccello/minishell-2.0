/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:09:47 by duccello          #+#    #+#             */
/*   Updated: 2025/09/09 17:56:50 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmds.h"
#include "data.h"
#include "list.h"
#include "token.h"
#include <stdlib.h>

void	free_array(char **c)
{
	int	i;

	if (c == NULL)
		return ;
	i = 0;
	while (c[i])
	{
		free(c[i]);
		c[i] = NULL;
		i++;
	}
	free(c);
	c = NULL;
}

void	free_cmd(t_cmd *c)
{
	if (c->path != NULL)
		free(c->path);
	if (c->argv != NULL)
		free_array(c->argv);
	if (c->envp != NULL)
		free_array(c->envp);
	if (c->in_file != NULL)
		free(c->in_file);
	if (c->out_file != NULL)
		free(c->out_file);
	if (c->append_file != NULL)
		free(c->append_file);
	if (c->delimiter != NULL)
		free(c->delimiter);
	free(c);
	c = NULL;
}

void	free_list(t_node *list)
{
	t_node	*curr;
	t_node	*prev;

	prev = list;
	curr = prev->next;
	while (curr != NULL)
	{
		free(prev->s);
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	free(prev->s);
	free(prev);
}

void	free_tokens(t_tok **tokens, t_data *data)
{
	size_t	i;

	i = 0;
	if (tokens != NULL)
	{
		while (i < data->n_tokens)
		{
			free(tokens[i]->s);
			tokens[i]->s = NULL;
			free(tokens[i++]);
		}
		free(tokens);
	}
}

void	free_data(t_data *data)
{
	size_t	i;

	if (data == NULL)
		return ;
	if (data->cmds != NULL)
	{
		i = 0;
		while (i < data->n_cmds)
		{
			if (data->cmds[i] != NULL)
				free_cmd(data->cmds[i]);
			i++;
		}
		free(data->cmds);
		data->cmds = NULL;
	}
	if (data->tokens != NULL)
		free_tokens(data->tokens, data);
	if (data->envp != NULL)
		free_list(data->envp);
	if (data->built_ins != NULL)
		free_array(data->built_ins);
	if (data->pipfd != NULL)
	{
		free(data->pipfd);
		data->pipfd = NULL;
	}
	free(data);
}
