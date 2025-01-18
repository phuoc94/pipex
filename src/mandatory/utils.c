/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:35:53 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/18 13:55:25 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	create_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		ft_perror("Create pipe failed", NULL);
		exit(EXIT_FAILURE);
	}
}

void	safe_dup2(int old_fd, int new_fd)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		ft_perror("Dup2 failed", NULL);
		exit(EXIT_FAILURE);
	}
}

int	create_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_perror("Create fork failed", NULL);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	close_fd(int fd)
{
	if (fd >= 0 && close(fd) == -1)
	{
		ft_perror("Close file descriptor failed", NULL);
		exit(EXIT_FAILURE);
	}
}

void	close_pipe(int fd[2])
{
	close_fd(fd[0]);
	close_fd(fd[1]);
}
