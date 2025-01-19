/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 16:06:27 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*get_cmd_path(char *cmd, char **envp)
{
	if (!cmd || !*cmd)
		return (NULL);
	if (cmd[0] == '/' || cmd[0] == '.')
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	if (!envp)
		return (NULL);
	return (find_cmd_path(cmd, envp));
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = split_with_quotes(cmd);
	cmd_path = get_cmd_path(args[0], envp);
	if (cmd_path == NULL)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: %s: command not found\n", args[0]);
		free_ft_split(&args);
		exit(127);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: %s: %s\n", args[0],
			strerror(errno));
		free(cmd_path);
		free_ft_split(&args);
		if (errno == ENOENT)
			exit(127);
		else
			exit(126);
	}
	free(cmd_path);
	free_ft_split(&args);
}
