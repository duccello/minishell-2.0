/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_and_operators.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:38:45 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 16:51:22 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_AND_OPERATORS_H
# define FD_AND_OPERATORS_H

typedef struct s_tok	t_tok;

void					check_operators(t_tok *token);
int						check_files(t_tok **tokens, int i);

#endif
