/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:06:32 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/24 19:23:44 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	execute(char *cmd, char **envp)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	if(!s_cmd || !s_cmd[0])
	{
		if (s_cmd)
			free(s_cmd);
		exit(1);
	}
	path = get_path(s_cmd[0], envp);
	if (!path)
		ft_exit(path, s_cmd, 0);
	if (cmd == 0 || cmd[0] == ' ')
		ft_exit(path, s_cmd, 2);
	if (cmd[0] == '/')
	{
		if (!access(cmd, X_OK))
			execve(cmd, s_cmd, envp);
		ft_exit(path, s_cmd, 3);
	}
	if (execve(path, s_cmd, envp) == -1)
		ft_exit(path, s_cmd, 1);
	ft_exit(path, s_cmd, 3);
}

int	child_process(char *argv[], int *fd, char **envp)
{
	int	fdc;

	close(fd[0]);
	fdc = open_file(argv[1], 0);
	if (fdc == -1)
	{
		perror("Failed to open input file");
		close(fdc);
		close(fd[1]);
		exit(1);
	}
	if (dup2(fdc, STDIN_FILENO) < 0)
	{
		perror("Failed to redirect stdin");
		exit(1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("Failed to redirect stdout");
		exit(1);
	}
	close(fdc);
	close(fd[1]);
	execute(argv[2], envp);
	return (0);
}

int	parnt_process(char *argv[], int *fd, char **envp)
{
	int	fdc;

	close(fd[1]);
	fdc = open_file(argv[4], 1);
	if (fdc == -1)
	{
		perror("Failed to open output file");
		exit(1);
	}
	if (dup2(fdc, STDOUT_FILENO) == -1)
	{
		perror("Failed to redirect stdin from pipe");
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Failed to redirect stdout to output file");
		exit(1);
	}
	close(fdc);
	close(fd[0]);
	execute(argv[3], envp);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Pipe failed");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == 0 && pid != -1)
			child_process(argv, fd, envp);
		pid2 = fork();
		if (pid2 == 0 && pid2 != -1)
			parnt_process(argv, fd, envp);
		close(fd[0]);
		close(fd[1]);
		wait(NULL);
		wait(NULL);
	}
	else
		perror("the number of arguments dosenet = 5");
	return (0);
}
