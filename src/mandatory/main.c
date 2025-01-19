/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 07:26:04 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:16:21 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status1;
	int	status2;

	validate_args(argc, argv);
	create_pipe(fd);
	pid1 = create_fork();
	if (pid1 == 0)
		handle_child1(fd, argv, envp);
	pid2 = create_fork();
	if (pid2 == 0)
		handle_child2(fd, argv, envp);
	close_fd(fd[1]);
	if ((waitpid(pid1, &status1, 0) == -1)
		|| (waitpid(pid2, &status2, 0) == -1))
	{
		ft_perror("Failed to wait for child process", NULL);
		return (EXIT_FAILURE);
	}
	close_fd(fd[0]);
	return (status2 >> 8 & 255);
}
