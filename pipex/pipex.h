/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:07:21 by rabu-shr          #+#    #+#             */
/*   Updated: 2025/01/24 15:32:38 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	execute(char *cmd, char **envp);
int		child_process(char *argv[], int *fd, char **envp);
void	error_handel(void);
int		open_file(char *file, int which);
char	*get_path(char *cmd, char **envp);
int		parnt_process(char *argv[], int *fd, char **envp);
char	*my_env(const char *key, char **envp);
void	ft_free(char **s_cmd);
void	free_function(char **s_cmd, char **paths);
void	ft_exit(char *path, char **s_cmd, int which);
#endif
