/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:37:56 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 13:31:05 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "operators.h"
#include "ft_fprintf.h"
#include "token.h"
#include <unistd.h>

void	interpret_operators(t_tok *token)
{
	if (token->quote == true || token->dquote == true)
		token->string = true;
	else if (ft_strncmp(token->s, "<", 2) == 0)
		token->input_operator = true;
	else if (ft_strncmp(token->s, ">", 2) == 0)
		token->output_operator = true;
	else if (ft_strncmp(token->s, "<<", 3) == 0)
		token->heredoc_operator = true;
	else if (ft_strncmp(token->s, ">>", 3) == 0)
		token->append_operator = true;
	else if (ft_strncmp(token->s, "|", 2) == 0)
		token->pipe = true;
	else
		token->string = true;
}

void interpret_files(t_tok **tokens, int i)
{
	if (tokens[i - 1]->input_operator == true)
	{
		if (tokens[i]->string == false)
			ft_fprintf(STDERR_FILENO, "syntax error\n");
		else
			tokens[i]->input_file = true;
	}
	else if (tokens[i - 1]->output_operator == true)
	{
		if (tokens[i]->string == false)
			ft_fprintf(STDERR_FILENO, "syntax error\n");
		else
			tokens[i]->output_file = true;
	}
	else if (tokens[i - 1]->heredoc_operator == true)
	{
		if (tokens[i]->string == false)
			ft_fprintf(STDERR_FILENO, "syntax error\n");
		else
			tokens[i]->heredoc_delimiter = true;
	}
	else if (tokens[i - 1]->append_operator == true)
	{
		if (tokens[i]->string == false)
			ft_fprintf(STDERR_FILENO, "syntax error\n");
		else
			tokens[i]->append_file = true;
	}
}

