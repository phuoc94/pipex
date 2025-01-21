/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:39 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/21 09:21:50 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	handle_cmd_not_found(char **args)
{
	if (!args || !args[0])
		return ;
	if (ft_strchr(args[0], '/') == NULL)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": Command not found\n", STDERR_FILENO);
	}
	else if (access(args[0], F_OK) == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": Command not found\n", STDERR_FILENO);
	}
	free_ft_split(&args);
	exit(127);
}

void	handle_permission_denied(char *cmd_path, char **args)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(args[0], STDERR_FILENO);
	ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	free(cmd_path);
	free_ft_split(&args);
	exit(126);
}

void	handle_execve_error(char *cmd_path, char **args)
{
	print_pipex_error(args[0]);
	free(cmd_path);
	free_ft_split(&args);
	if (errno == ENOENT)
		exit(127);
	else
		exit(126);
}
