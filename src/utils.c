/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:35:53 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/09 13:26:34 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	create_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		ft_perror("Create pipe failed", NULL);
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
		ft_perror("Create fork failed", NULL);
		exit(EXIT_FAILURE);
	}

	return (pid);
}
