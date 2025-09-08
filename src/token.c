/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:43:50 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 18:21:37 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "expand.h"
#include "libft.h"
#include "fd_and_operators.h"
#include "token.h"
#include <readline/readline.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

t_tok	**tokenize(t_data *data, char *s)
{
	t_tok	**tokens;
	char	*tracker;
	size_t	i;

	tracker = ft_strdup(s);
	i = 0;
	while (tracker[i] != '\0')
		tracker[i++] = '-';
	data->n_tokens = count_tokens(s, tracker);
	tokens = malloc(sizeof(t_tok *) * (data->n_tokens));
	if (tokens == NULL)
		return (NULL);
	if (create_tokens(data, tokens) == 1)
	{
		clean_tokens(tokens, data);
		return (NULL);
	}
	return (tokens);
}

int		create_tokens(t_data *data, t_tok **tokens, char *tracker)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < data->n_tokens)
	{
		tokens[i] = populate_token(s, tracker, &j);
		init_token(tokens[i], data);
		trim_spaces(tokens[i]);
		trim_quotes(tokens[i]);
		expand(tokens[i]);
		check_operators(tokens[i]);
		i++;
	}
	if (tokens[i]->string == false)
	{
		ft_printf(STDERR_FILENO, "syntax error\n");
		return (1);
	}
	i = 1;
	while (i < data->n_tokens)
		if (check_files(tokens, i++) == 1)
			return (1);
	return (tokens);
}

t_tok	*populate_token(char *s, char *tracker, int *j)
{
	t_tok	*token;
	int		start;
	int		len;

	len = 0;
	token = malloc(sizeof(t_tok));
	if (token == NULL)
		return (NULL);
	while (tracker[*j] == '-')
		(*j)++;
	start = *j;
	if (tracker[*j] == '+')
	{
		(*j)++;
		len++;
		while (tracker[*j] != '\0' && tracker[*j] != '+')
		{
			(*j)++;
			len++;
		}
	}
	token->s = malloc(len + 2);
	ft_strlcpy(token->s, &s[start], len + 1);
	token->quote = false;
	return (token);
}

void	init_token(t_tok *token, t_data *data)
{
	token->data = data;
	token->quote = false;
	token->dquote = false;
	token->argument = false;
	token->input_operator = false;
	token->input_file = false;
	token->output_operator = false;
	token->output_file = false;
	token->append_operator = false;
	token->append_file = false;
	token->heredoc_operator = false;
	token->heredoc_delimiter = false;
	token->heredoc_text = false;
	token->pipe = false;
}

void	toggle_quotes(char c, bool *in_quote, bool *in_dquote)
{
	if (c == '\'')
	{
		if (*in_quote == false && *in_dquote == false)
			*in_quote = true;
		else if (*in_quote == true && *in_dquote == false)
			*in_quote = false;
	}
	else if (c == '"')
	{
		if (*in_dquote == false && *in_quote == false)
			*in_dquote = true;
		else if (*in_dquote == true && *in_quote == false)
			*in_dquote = false;
	}
}

int	count_tokens(char *s, char *tracker)
{
	int		counter;
	bool	in_quote;
	bool	in_dquote;
	bool	in_word;
	int		i;

	in_quote = false;
	in_dquote = false;
	in_word = false;
	counter = 0;
	i = 0;
	while (s[i] != '\0' && tracker[i] != '\0')
	{
		if (in_quote == false && in_dquote == false)
		{
			if (ft_strncmp(&s[i], ">>", 2) == 0
					|| ft_strncmp(&s[i], "<<", 2) == 0)
			{
				in_word = false;
				counter++;
				tracker[i] = '+';
				i++;
			}
			else if (s[i] == '>' || s[i] == '<' || s[i] == '|')
			{
				in_word = false;
				counter++;
				tracker[i] = '+';
			}
			else if (s[i] != ' ' && in_word == false)
			{
				in_word = true;
				counter++;
				tracker[i] = '+';
			}
			else if (s[i] == ' ' && in_word == true)
				in_word = false;
		}
		toggle_quotes(s[i], &in_quote, &in_dquote);
		i++;
	}
	return (counter);
}
