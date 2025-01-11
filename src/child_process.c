/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:21:24 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/11 14:58:41 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	handle_child1(int *fd, char **argv, char **envp)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_perror("Failed to open file", argv[1]);
		exit(EXIT_FAILURE);
	}
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close_pipe(fd);
	execute_command(argv[2], envp);
	close(file1);
	exit(EXIT_SUCCESS);
}

void	handle_child2(int *fd, char **argv, char **envp)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 < 0)
	{
		ft_perror("Failed to create file", argv[4]);
		exit(EXIT_FAILURE);
	}
	dup2(file2, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close_pipe(fd);
	execute_command(argv[3], envp);
	close(file2);
	exit(EXIT_SUCCESS);
}
