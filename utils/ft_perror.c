/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:05:58 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/07 21:46:18 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <errno.h>  // errno
#include <string.h> // strerror

void	ft_perror(char *message, char *detail)
{
	if (message)
	{
		ft_putstr_fd("Error: ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		if (detail)
		{
			ft_putstr_fd(": ", STDERR_FILENO);
			ft_putstr_fd(detail, STDERR_FILENO);
		}
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	if (errno)
	{
		ft_putstr_fd("Errno: ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}
