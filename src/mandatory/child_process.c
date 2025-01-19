/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:48:31 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	handle_child1(int *fd, char **argv, char **envp)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: %s: %s\n", argv[1],
			strerror(errno));
		exit(EXIT_FAILURE);
	}
	safe_dup2(file1, STDIN_FILENO);
	safe_dup2(fd[1], STDOUT_FILENO);
	close_pipe(fd);
	execute_command(argv[2], envp);
	close_fd(file1);
	exit(EXIT_SUCCESS);
}

void	handle_child2(int *fd, char **argv, char **envp)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
	{
		ft_printf_fd(STDERR_FILENO, "pipex: %s: %s\n", argv[4],
			strerror(errno));
		exit(EXIT_FAILURE);
	}
	safe_dup2(file2, STDOUT_FILENO);
	safe_dup2(fd[0], STDIN_FILENO);
	close_pipe(fd);
	execute_command(argv[3], envp);
	close_fd(file2);
	exit(EXIT_SUCCESS);
}
