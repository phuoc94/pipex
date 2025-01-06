/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:00:39 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:36:18 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * ft_putstr_fd - Outputs the string 's' to the given file descriptor 'fd'.
 * @s: The string to output.
 * @fd: The file descriptor on which to write.
 *
 * This function writes the string 's' to the file descriptor specified by 'fd'.
 * If 's' is NULL, the function does nothing.
 */
void	ft_putstr_fd(const char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}
