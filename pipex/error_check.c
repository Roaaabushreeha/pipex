/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:04:50 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/24 15:37:53 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **s_cmd)
{
	int	i;

	i = 0;
	while (s_cmd[i])
	{
		free(s_cmd[i]);
		i++;
	}
	free(s_cmd);
}

void	ft_exit(char *path, char **s_cmd, int which)
{
	if (which == 0)
		perror("Command not found");
	if (which == 1)
		perror("Execution failed");
	if (which == 2)
		error_handel();
	free(path);
	ft_free(s_cmd);
	exit(1);
}
