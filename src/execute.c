/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/11 19:05:24 by phuocngu         ###   ########.fr       */
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
	char	*cmd_path_tmp;
	int		i;

	i = 0;
	path = find_env_var("PATH", envp);
	paths = ft_split(path, ':');
	while (paths[i])
	{
		cmd_path_tmp = ft_strjoin(paths[i], "/");
		cmd_path = ft_strjoin(cmd_path_tmp, cmd);
		free(cmd_path_tmp);
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

	args = ft_split(cmd, ' ');
	if (args == NULL)
	{
		ft_perror("Failed to split command", cmd);
		exit(EXIT_FAILURE);
	}
	cmd_path = get_cmd_path(args[0], envp);
	if (cmd_path == NULL)
	{
		ft_perror("Command not found", args[0]);
		free_ft_split(args);
		exit(127);
	}
	if (execve(cmd_path, args, envp) == -1)
	{
		ft_perror("Command execution failed", args[0]);
		free_ft_split(args);
		exit(EXIT_FAILURE);
	}
	free(cmd_path);
	free_ft_split(args);
}
