/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/21 09:57:04 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*get_cmd_path(char *cmd, char **envp)
{
	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
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
		handle_cmd_not_found(args);
	else if (access(cmd_path, F_OK) != 0)
		handle_cmd_not_found(args);
	else if (access(cmd_path, X_OK) != 0)
		handle_permission_denied(cmd_path, args);
	else if (execve(cmd_path, args, envp) == -1)
		handle_execve_error(cmd_path, args);
	free(cmd_path);
	free_ft_split(&args);
}
