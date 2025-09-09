/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 17:08:42 by duccello          #+#    #+#             */
/*   Updated: 2025/09/04 16:22:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "cmds.h"
#include "data.h"
#include "libft.h"
#include "list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t	count_bins(t_data *data)
{
	size_t	i;
	size_t	bins;

	i = 0;
	bins = 0;
	while (i < data->n_cmds)
	{
		if (data->cmds[i]->argv[0] != NULL
			&& cmd_is_built_in(data->cmds[i]->argv[0],
				data->built_ins) == false)
			bins++;
		i++;
	}
	return (bins);
}

int	char_counter(char *input, char c)
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (input[i])
	{
		if (input[i] == c)
			amount++;
		i++;
	}
	return (amount);
}

char	**create_array(t_node *envp)
{
	char	**arr;
	t_node	*curr;
	int		len;
	int		i;

	len = 0;
	curr = envp;
	while (curr != NULL)
	{
		len++;
		curr = curr->next;
	}
	arr = malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);
	curr = envp;
	i = 0;
	while (curr != NULL)
	{
		arr[i++] = ft_strdup(curr->s);
		curr = curr->next;
	}
	arr[i] = NULL;
	return (arr);
}

int	find_equal(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == '=')
			return (len);
		len++;
	}
	return (-1);
}
