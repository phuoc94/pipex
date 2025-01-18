/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/18 18:05:48 by phuocngu         ###   ########.fr       */
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
	if (args == NULL)
	{
		ft_perror("Failed to split command", cmd);
		exit(EXIT_FAILURE);
	}
	cmd_path = get_cmd_path(args[0], envp);
	if (cmd_path == NULL)
	{
		ft_perror("Command not found", args[0]);
		free_ft_split(&args);
		exit(127);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		ft_perror("Command execution failed", args[0]);
		free(cmd_path);
		free_ft_split(&args);
		exit(EXIT_FAILURE);
	}
	free(cmd_path);
	free_ft_split(&args);
}
