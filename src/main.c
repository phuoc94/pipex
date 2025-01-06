/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 07:26:04 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 20:48:33 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	int fd[2];

	validate_args(argc, argv);
	create_pipe(fd);
	int pid1 = create_fork();

	if (pid1 == 0)
	{
		close(fd[0]);
		ft_printf("Child\n");
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		ft_printf("Parent\n");
		close(fd[0]);
	}


	return (EXIT_SUCCESS);
}
