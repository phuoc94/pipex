/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 07:26:04 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 16:23:20 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static	void	wait_for_child(int pid, int *status)
{
	if (waitpid(pid, status, 0) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
}

static	void	handle_parent(int fd[2], int pid1, int pid2)
{
	int	status1;
	int	status2;

	close_fd(fd[1]);
	close_fd(fd[0]);
	wait_for_child(pid1, &status1);
	wait_for_child(pid2, &status2);
	exit(status2 >> 8 & 255);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	validate_args(argc, argv);
	create_pipe(fd);
	pid1 = create_fork();
	if (pid1 == 0)
		handle_child1(fd, argv, envp);
	pid2 = create_fork();
	if (pid2 == 0)
		handle_child2(fd, argv, envp);
	handle_parent(fd, pid1, pid2);
	return (0);
}
