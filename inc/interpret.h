/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:05:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/09 16:08:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRET_H
# define INTERPRET_H

typedef struct s_data	t_data;

void	interpret(t_data *data, char *s);
int		init(t_data *data, char *s);

#endif
