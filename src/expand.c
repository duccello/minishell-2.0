/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:30:23 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/11 11:38:25 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "expand.h"
#include "libft.h"
#include "list.h"
#include "token.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void	expand(t_tok *token)
{
	if (token->quote == true)
		return ;
	if (token->s[0] == '$' && token->s[1] == '?')
	{
		free(token->s);
		token->s = ft_itoa(token->data->ret_val);
	}
	else if (token->s[0] == '$' && token->s[1] != '\0'
		&& ft_isspace(token->s[1]) == false)
	{
		token->s = expand_var(token);
		if (token->s == NULL)
			token->s = ft_strdup("");
	}
}

char	*expand_var(t_tok *token)
{
	char	*s;
	t_node	*curr;
	int		len_tok;
	int		len_list;

	len_tok = ft_strlen(token->s) - 1;
	curr = token->data->envp;
	s = NULL;
	while (curr != NULL)
	{
		len_list = find_equal(curr->s);
		if (ft_strncmp(curr->s, &(token->s[1]), len_tok) == 0
			&& len_tok == len_list)
		{
			free(token->s);
			s = ft_strdup(&(curr->s[len_list + 1]));
			return (s);
		}
		curr = curr->next;
	}
	free(token->s);
	return (s);
}
