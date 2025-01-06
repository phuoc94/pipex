/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:03:49 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:35:16 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_putendl_fd - Outputs the string 's' to the given file descriptor
 * followed by a newline.
 * @s: The string to output.
 * @fd: The file descriptor on which to write.
 *
 * This function writes the string 's' to the file descriptor 'fd' and
 * appends a newline character at the end. If 's' is NULL, the function
 * does nothing.
 */
void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
	write(fd, "\n", 1);
}
