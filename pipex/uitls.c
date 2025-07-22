/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:07:02 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/24 19:22:42 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handel(void)
{
	perror("Error");
	exit(1);
}

int	open_file(char *file, int which)
{
	int	openf;

	if (which == 0)
	{
		openf = open(file, O_RDONLY);
	}
	else if (which == 1)
	{
		openf = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (openf == -1)
	{
		return (-1);
	}
	return (openf);
}

char	*my_env(const char *key, char **envp)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strncmp(sub, key, ft_strlen(key)) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

void	free_function(char **s_cmd, char **paths)
{
	ft_free(s_cmd);
	ft_free(paths);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*exec;
	char	**paths;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	paths = ft_split(my_env("PATH", envp), ':');
	if (!paths)
		return (NULL);
	s_cmd = ft_split(cmd, ' ');
	while (paths[++i])
	{
		path_part = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_function(s_cmd, paths);
			return (exec);
		}
		free(exec);
	}
	free_function(s_cmd, paths);
	return (NULL);
}
