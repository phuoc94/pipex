/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:39 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 17:41:20 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void handle_cmd_not_found(char **args)
{
	ft_printf_fd(STDERR_FILENO, "pipex: %s: No such file or directory\n", args[0]);
	free_ft_split(&args);
	exit(127);
}

void handle_permission_denied(char *cmd_path, char **args)
{
	ft_printf_fd(STDERR_FILENO, "pipex: %s: Permission denied\n", args[0]);
	free(cmd_path);
	free_ft_split(&args);
	exit(126);
}

void handle_execve_error(char *cmd_path, char **args)
{
	ft_printf_fd(STDERR_FILENO, "pipex: %s: %s\n", args[0], strerror(errno));
	free(cmd_path);
	free_ft_split(&args);
	if (errno == ENOENT)
		exit(127);
	else
		exit(126);
}
