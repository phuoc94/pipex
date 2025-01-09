/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/09 16:39:15 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_env_var(char *var, char **envp)
{
	int		i;
	char	*value;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], var, ft_strlen(var)) == 0)
		{
			value = ft_strchr(envp[i], '=') + 1;
			return (value);
		}
		i++;
	}
	return (NULL);
}

static char	*find_cmd_path(char *cmd, char **envp)
{
	char	*path;
	char	**paths;
	char	*cmd_path;
	int		i;

	i = 0;
	path = find_env_var("PATH", envp);
	paths = ft_split(path, ':');
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(cmd_path, cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			free_ft_split(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_ft_split(paths);
	return (NULL);
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	if (args == NULL)
	{
		ft_perror("Failed to split command", cmd);
		exit(EXIT_FAILURE);
	}
	cmd_path = find_cmd_path(args[0], envp);
	if (cmd_path == NULL)
	{
		ft_perror("Command not found", args[0]);
		free_ft_split(args);
		exit(EXIT_FAILURE);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		ft_perror("Command execution failed", args[0]);
		free_ft_split(args);
		exit(EXIT_FAILURE);
	}
	free_ft_split(args);
}
