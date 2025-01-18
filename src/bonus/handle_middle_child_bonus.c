/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_middle_child_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/18 13:45:01 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	handle_middle_child(t_pipex *pipex, int i)
{
	safe_dup2(pipex->prev_fd, STDIN_FILENO);
	safe_dup2(pipex->fd[1], STDOUT_FILENO);
	close_fd(pipex->prev_fd);
	close_fd(pipex->fd[0]);
	close_fd(pipex->fd[1]);
	if (pipex->here_doc == 1)
		execute_command(pipex->argv[i + 3], pipex->envp);
	else
		execute_command(pipex->argv[i + 2], pipex->envp);
	exit(EXIT_FAILURE);
}
