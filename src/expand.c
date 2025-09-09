/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:30:23 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/05 11:50:34 by sgaspari         ###   ########.fr       */
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

void	expand(t_tok *token)
{
	int	i;

	if (token->quote == true)
		return ;
	i = 0;
	while (token->s[i] != '\0')
	{
		if (token->s[i] == '$' && token->s[i + 1] == '?')
			token->s = ft_itoa(token->data->ret_val);
		else if (token->s[i] == '$' && token->s[i + 1] != '\0'
			&& ft_isspace(token->s[i + 1]) == false)
		{
			token->s = expand_var(token);
			if (token->s == NULL)
				token->s = "";
		}
		i++;
	}
}

char	*expand_var(t_tok *token)
{
	char	*s;
	t_node	*curr;
	int		len_tok;
	int		len_list;

	len_tok = ft_strlen(&token->s[1]);
	curr = token->data->envp;
	s = NULL;
	while (curr != NULL)
	{
		len_list = find_equal(curr->s);
		if (ft_strncmp(curr->s, &(token->s[1]), len_tok) == 0
			&& len_tok == len_list)
			s = ft_strdup(&(curr->s[len_list + 1]));
		curr = curr->next;
	}
	return (s);
}
