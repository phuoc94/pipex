/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:26:52 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 19:15:26 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	validate_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid argument.\n", 2);
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}
