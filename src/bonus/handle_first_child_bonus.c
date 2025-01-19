/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_first_child_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:01:02 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:49:13 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	handle_here_doc(t_pipex *pipex)
{
	safe_dup2(pipex->prev_fd, STDIN_FILENO);
	close_fd(pipex->prev_fd);
	safe_dup2(pipex->fd[1], STDOUT_FILENO);
	close_pipe(pipex->fd);
	execute_command(pipex->argv[3], pipex->envp);
	exit(EXIT_SUCCESS);
}

static void	handle_non_here_doc(t_pipex *pipex)
{
	int	file1;

	file1 = open(pipex->argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: %s: %s\n", pipex->argv[1],
			strerror(errno));
		exit(EXIT_FAILURE);
	}
	safe_dup2(file1, STDIN_FILENO);
	safe_dup2(pipex->fd[1], STDOUT_FILENO);
	close_pipe(pipex->fd);
	close_fd(file1);
	execute_command(pipex->argv[2], pipex->envp);
	exit(EXIT_SUCCESS);
}

void	handle_first_child(t_pipex *pipex)
{
	if (pipex->here_doc == 1)
		handle_here_doc(pipex);
	else
		handle_non_here_doc(pipex);
}
