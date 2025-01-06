/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:35:53 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 19:58:30 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	create_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		ft_putstr_fd("Error: Pipe failed.\n", 2);
		exit(EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}

int	create_fork(void)
{
	int pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error: Fork failed.\n", 2);
		exit(EXIT_FAILURE);
	}

	return (pid);
}
