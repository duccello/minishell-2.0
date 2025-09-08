/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:07:06 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 13:25:00 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
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
	size_t	i;

	i = 0;
	data->tokens = tokenize(data, s);
	while (i < data->n_tokens)
	{
		printf("%s\n", data->tokens[i]->s);
		i++;
	}
}
