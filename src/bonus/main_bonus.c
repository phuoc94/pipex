/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 07:26:04 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/12 20:11:11 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	execute_pipes(t_pipex *pipex)
{
	int	pid;
	int	i;

	i = 0;
	while (i < pipex->argc - 3)
	{
		create_pipe(pipex->fd);
		pid = create_fork();
		if (pid == 0)
		{
			if (i == 0)
				handle_first_child(pipex);
			else if (i == pipex->argc - 4)
				handle_last_child(pipex);
			else
				handle_middle_child(pipex);
		}
		close(pipex->prev_fd);
		pipex->prev_fd = pipex->fd[0];
		close(pipex->fd[1]);
		i++;
	}
	pipex->last_pid = pid;
	close(pipex->prev_fd);
}

int	wait_for_children(t_pipex *pipex)
{
	int	status;
	int	last_status;
	int	i;
	int	pid;

	i = 0;
	last_status = 0;
	while (i < pipex->argc - 3)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
		{
			ft_perror("Failed to wait for child process", NULL);
			return (EXIT_FAILURE);
		}
		if (pid == pipex->last_pid)
			last_status = status;
		i++;
	}
	return (last_status >> 8 & 255);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	validate_args(argc, argv);
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	pipex.prev_fd = -1;
	pipex.last_pid = -1;
	execute_pipes(&pipex);
	return (wait_for_children(&pipex));
}
