/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:38:45 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/10 10:58:28 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

typedef struct s_tok	t_tok;
typedef struct s_cmd	t_cmd;

int						check_files(t_tok **tokens, int i);
void					set_fds(t_cmd *c);

#endif
