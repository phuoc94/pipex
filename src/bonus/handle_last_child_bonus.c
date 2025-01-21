/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_last_child_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:04:29 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/21 08:53:11 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	handle_here_doc_output(t_pipex *pipex, int index_output_file)
{
	int	file2;

	file2 = open(pipex->argv[index_output_file], O_WRONLY | O_CREAT | O_APPEND,
			0644);
	if (file2 < 0)
	{
		print_pipex_error(pipex->argv[index_output_file]);
		exit(EXIT_FAILURE);
	}
	safe_dup2(pipex->prev_fd, STDIN_FILENO);
	safe_dup2(file2, STDOUT_FILENO);
	close_fd(pipex->prev_fd);
	close_fd(file2);
	execute_command(pipex->argv[pipex->argc - 2], pipex->envp);
	exit(EXIT_SUCCESS);
}

static void	handle_non_here_doc_output(t_pipex *pipex, int index_output_file)
{
	int	file2;

	file2 = open(pipex->argv[index_output_file], O_WRONLY | O_CREAT | O_TRUNC,
			0644);
	if (file2 < 0)
	{
		print_pipex_error(pipex->argv[index_output_file]);
		exit(EXIT_FAILURE);
	}
	safe_dup2(pipex->prev_fd, STDIN_FILENO);
	safe_dup2(file2, STDOUT_FILENO);
	close_fd(pipex->prev_fd);
	close_fd(file2);
	execute_command(pipex->argv[pipex->argc - 2], pipex->envp);
	exit(EXIT_SUCCESS);
}

void	handle_last_child(t_pipex *pipex)
{
	int	index_output_file;

	index_output_file = pipex->argc - 1;
	if (pipex->here_doc == 1)
		handle_here_doc_output(pipex, index_output_file);
	else
		handle_non_here_doc_output(pipex, index_output_file);
}
