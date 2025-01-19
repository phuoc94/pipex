/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 07:26:04 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 16:03:56 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	execute_pipes(t_pipex *pipex)
{
	int	pid;
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		create_pipe(pipex->fd);
		pid = create_fork();
		if (pid == 0)
		{
			if (i == 0)
				handle_first_child(pipex);
			else if (i == pipex->cmd_count - 1)
				handle_last_child(pipex);
			else
				handle_middle_child(pipex, i);
		}
		close_fd(pipex->prev_fd);
		pipex->prev_fd = pipex->fd[0];
		close_fd(pipex->fd[1]);
		i++;
	}
	pipex->last_pid = pid;
	close_fd(pipex->prev_fd);
}

int	wait_for_children(t_pipex *pipex)
{
	int	status;
	int	last_status;
	int	i;
	int	pid;

	i = 0;
	last_status = 0;
	while (i < pipex->cmd_count)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		if (pid == pipex->last_pid)
			last_status = status;
		i++;
	}
	return ((last_status >> 8) & 255);
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
	pipex.here_doc = false;
	pipex.limiter = NULL;
	pipex.cmd_count = argc - 3;
	if (argc >= 3 && !ft_strcmp(argv[1], "here_doc"))
	{
		pipex.here_doc = true;
		pipex.limiter = argv[2];
		pipex.cmd_count = argc - 4;
		read_here_doc(&pipex);
	}
	execute_pipes(&pipex);
	return (wait_for_children(&pipex));
}
