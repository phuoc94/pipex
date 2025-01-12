/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/12 18:03:48 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	handle_first_child(t_pipex *pipex)
{
	int	file1;

	file1 = open(pipex->argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_perror("Failed to open file", pipex->argv[1]);
		exit(EXIT_FAILURE);
	}
	dup2(file1, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close_pipe(pipex->fd);
	execute_command(pipex->argv[2], pipex->envp);
	close(file1);
	exit(EXIT_SUCCESS);
}

void	handle_middle_child(t_pipex *pipex)
{
	dup2(pipex->prev_fd, STDIN_FILENO);
	dup2(pipex->fd[1], STDOUT_FILENO);
	close_pipe(pipex->fd);
	close(pipex->prev_fd);
	execute_command(pipex->argv[2], pipex->envp);
	exit(EXIT_SUCCESS);
}

void	handle_last_child(t_pipex *pipex)
{
	int	file2;
	int	index_file;

	index_file = pipex->argc - 1;
	file2 = open(pipex->argv[index_file], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
	{
		ft_perror("Failed to create file", pipex->argv[index_file]);
		exit(EXIT_FAILURE);
	}
	dup2(pipex->prev_fd, STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(pipex->prev_fd);
	execute_command(pipex->argv[pipex->argc - 2], pipex->envp);
	close(file2);
	exit(EXIT_SUCCESS);
}
