/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 07:26:04 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/12 18:55:11 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		pid;
	int		status;
	int		i;
	t_pipex	pipex;

	validate_args(argc, argv);
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	pipex.prev_fd = -1;
	i = 0;
	while (i < argc - 3)
	{
		create_pipe(pipex.fd);
		pid = create_fork();
		if (pid == 0)
		{
			if (i == 0)
				handle_first_child(&pipex);
			else if (i == argc - 4)
				handle_last_child(&pipex);
			else
				handle_middle_child(&pipex);
		}
		close(pipex.prev_fd);
		pipex.prev_fd = pipex.fd[0];
		close(pipex.fd[1]);
		i++;
	}
	close(pipex.prev_fd);
	i = 0;
	while (i < argc - 3)
	{
		if (waitpid(-1, &status, 0) == -1)
		{
			ft_perror("Failed to wait for child process", NULL);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (status >> 8 & 255);
}
