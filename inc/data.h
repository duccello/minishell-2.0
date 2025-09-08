/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:29:38 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 13:17:17 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

typedef struct s_tok t_tok;
typedef struct s_node t_node;

typedef struct s_data
{
	t_tok	**tokens;
	char	**built_ins;
	t_node	*envp;
	int		n_tokens;
	int		ret_val;
}	t_data;

t_data	*create_data(char **envp);

#endif
