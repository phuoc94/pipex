/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/21 09:39:47 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	handle_child1(int fd[2], char **argv, char **envp)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		print_pipex_error(argv[1]);
		close_pipe(fd);
		exit(EXIT_FAILURE);
	}
	close_fd(fd[0]);
	safe_dup2(file1, STDIN_FILENO);
	close_fd(file1);
	safe_dup2(fd[1], STDOUT_FILENO);
	close_fd(fd[1]);
	execute_command(argv[2], envp);
}

void	handle_child2(int fd[2], char **argv, char **envp)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
	{
		print_pipex_error(argv[4]);
		close_pipe(fd);
		exit(EXIT_FAILURE);
	}
	close_fd(fd[1]);
	safe_dup2(fd[0], STDIN_FILENO);
	close_fd(fd[0]);
	safe_dup2(file2, STDOUT_FILENO);
	close_fd(file2);
	execute_command(argv[3], envp);
}
