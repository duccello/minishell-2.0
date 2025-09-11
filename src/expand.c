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

static char		*handle_expansion(t_tok *token, size_t i);
static size_t	find_len(char *str, char c);
char			*replace_key_with_value(char *token_string, char *value,
					size_t key_len);
static char		*skip_expansion(char *token_string, size_t key_len);

void	expand(t_tok *token)
{
	size_t	i;

	i = 0;
	if (token->quote == true)
		return ;
	while (token->s[i] != '\0')
	{
		if (token->s[i] == '$' && token->s[i + 1] == '?')
		{
			free(token->s);
			token->s = ft_itoa(token->data->ret_val);
			i += 2;
		}
		else if (token->s[i] == '$' && token->s[i + 1] != '\0'
			&& ft_isspace(token->s[i + 1]) == false)
		{
			i++;
			token->s = handle_expansion(token, i);
			i = 0;
		}
		else
			i++;
	}
}

static char	*handle_expansion(t_tok *token, size_t i)
{
	char	*new_string;
	char	*key;
	char	*value;
	size_t	key_len;

	new_string = NULL;
	key_len = find_len(token->s, '$');
	key = malloc(key_len + 1 * sizeof(char));
	if (key == NULL)
		return (NULL);
	ft_strlcpy(key, &token->s[i], key_len + 1);
	value = getenv(key);
	if (value != NULL)
		new_string = replace_key_with_value(token->s, value, key_len + 1);
	else
		new_string = skip_expansion(token->s, key_len + 1);
	free(key);
	return (new_string);
}

char	*replace_key_with_value(char *token_string, char *value, size_t key_len)
{
	char	*new_string;
	size_t	i;
	size_t	j;
	size_t	k;
	int		len;

	len = (ft_strlen(token_string) - key_len + ft_strlen(value) + 1);
	new_string = malloc(len * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (token_string[i] != '\0' && token_string[i] != '$')
	{
		new_string[i] = token_string[i];
		i++;
	}
	j = i + key_len;
	k = 0;
	while (value[k] != '\0')
		new_string[i++] = value[k++];
	while (token_string[j] != '\0')
		new_string[i++] = token_string[j++];
	new_string[i] = '\0';
	free(token_string);
	return (new_string);
}

static char	*skip_expansion(char *token_string, size_t key_len)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	new_string = malloc((ft_strlen(token_string) - key_len + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (token_string[i] != '\0' && token_string[i] != '$')
	{
		new_string[i] = token_string[i];
		i++;
	}
	j = i + key_len;
	while (token_string[j] != '\0')
		new_string[i++] = token_string[j++];
	new_string[i] = '\0';
	free(token_string);
	return (new_string);
}

static size_t	find_len(char *str, char c)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		i++;
	while (str[i] != '\0' && (ft_isalnum(str[i]) || str[i] == '_'))
	{
		i++;
		len++;
	}
	return (len);
}