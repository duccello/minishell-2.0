/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:02:04 by sgaspari          #+#    #+#             */
/*   Updated: 2025/09/01 12:10:19 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_fprintf.h"
#include "built_in.h"
#include "cmds.h"

void	ft_exit(t_cmd *cmd)
{
	uint8_t	status;

	ft_fprintf(cmd->out_fd, "exit\n");
	if (cmd->argv[1] == NULL)
		exit (EXIT_SUCCESS);
	else
	{
		status = (uint8_t) ft_atoi(cmd->argv[1]);
		exit (status);
	}
}
