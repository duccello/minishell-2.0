/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:08:49 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 13:40:50 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include <stdbool.h>

typedef struct s_data t_data;
typedef struct s_cmd t_cmd;

typedef struct s_tok
{
	t_data	*data;
	char	*s;
	bool	quote;
	bool	dquote;
	bool	argument;
	bool	input_operator;
	bool	input_file;
	bool	output_operator;
	bool	output_file;
	bool	append_operator;
	bool	append_file;
	bool	heredoc_operator;
	bool	heredoc_delimiter;
	bool	heredoc_text;
	bool	pipe;
	bool	string;
}	t_tok;

t_tok	**tokenize(t_data *data, char *s);
t_tok	*populate_token(char *s, char *tracker, int *j);
void	init_token(t_tok *token, t_data *data);
void	trim_quotes(t_tok *token);
void	trim_spaces(t_tok *token);
int		count_tokens(char *s, char *tracker);


#endif
