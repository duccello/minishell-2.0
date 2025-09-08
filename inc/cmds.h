/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:55:25 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/08 17:01:49 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMDS_H
# define CMDS_H

typedef struct s_data t_data;
typedef struct s_tok t_tok;

typedef struct s_cmd
{	
	t_data	*data;							// echo "hello world" > file
	char 	**argv;  						// argv[0] = "echo"; argv[1] = "hello world"
	char	*in_file;						// NULL
	char	*out_file;						// file
}	t_cmd;

t_cmd	**create_cmds(t_data *data);

