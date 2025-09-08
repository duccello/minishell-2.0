/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:09:47 by duccello          #+#    #+#             */
/*   Updated: 2025/09/08 16:43:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "data.h"
#include "list.h"
#include "token.h"
#include <stdlib.h>

void	free_array(char **c)
{
	int	i;

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
	if (c->argv != NULL)
		free_array(c->argv);
	if (c->paths != NULL)
		free_array(c->paths);
	if (c->limiter != NULL)
	{
		free(c->limiter);
		c->limiter = NULL;
	}
	if (c->infile != NULL)
	{
		free(c->infile);
		c->infile = NULL;
	}
	if (c->outfile != NULL)
	{
		free(c->outfile);
		c->outfile = NULL;
	}
	free(c);
	c = NULL;
}

void	free_list(t_node *list)
{
	t_node *curr;
	t_node *prev;

	prev = list;
	curr = prev->next;
	while (curr != NULL)
	{
		free(prev);
		prev = curr;
		curr = curr->next;
	}
}

void	clean_tokens(t_tokens **tokens, t_data *data)
{
	int	i;

	i = 0;
	if (tokens != NULL)
	{
		while (i < data->n_tokens)
		{
			free(tokens[i]->s);
			free(tokens[i++]);
		}
		free(tokens);
	}
}

void	clean_data(t_data *data)
{
	if (data->envp != NULL)
		free_list(data->envp);
	if (data->built_ins != NULL)
		free_array(data->built_ins);
}

