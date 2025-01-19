/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:32:21 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:37:14 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(char *s, int fd)
{
	int	i;
	int	result;

	result = 0;
	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		result = write(fd, &s[i], 1);
		if (result == -1)
			return (result);
		i++;
	}
	return (i);
}
