/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:10:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/05 14:25:25 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "libft.h"
#include <stdlib.h>
#include <stdbool.h>

static int	get_len(int len);

void	trim_quotes(t_tok *token)
{
	char	*s;
	int		len;
	int		i;

	len = (int) ft_strlen(token->s);
	if ((token->s[0] == '"' && token->s[len - 1] == '"')
			|| (token->s[0] == '\'' && token->s[len - 1] == '\''))
	{
		if (token->s[0] == '\'' && token->s[len - 1] == '\'')
			token->quote = true;
		if (token->s[0] == '"' && token->s[len - 1] == '"')
			token->dquote = true;
		len -= 2;
		s = malloc(len + 1);
		if (s == NULL)
			return ;
		i = 0;
		while (i < len)
		{
			s[i] = token->s[i + 1];
			i++;
		}
		s[i] = '\0';
		token->s = ft_strdup(s);
		free(s);
	}
}

void	trim_spaces(t_tok *token)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	len = get_len((int)ft_strlen(token->s));
	s = malloc(len + 1);
	if (s == NULL)
	{
		perror("malloc");
		return ;
	}
	i = 0;
	while (token->s[i] == ' ')
		i++;
	j = 0;
	while (j < len)
	{
		s[j] = token->s[i + j];
		j++;
	}
	s[j] = '\0';
	token->s = ft_strdup(s);
	free(s);
}

static int	get_len(int len)
{
	int		i;
	int		j;

	i = 0;
	while (token->s[i] == ' ' && i < len)
		i++;
	j = 0;
	while (token->s[len - 1] == ' ' && j < len)
	{
		j++;
		len--;
	}
	return (len);
}
