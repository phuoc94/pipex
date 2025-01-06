/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:32:21 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/14 17:49:29 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(char *s)
{
	int	i;
	int	result;

	result = 0;
	if (!s)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
	{
		result = write(1, &s[i], 1);
		if (result == -1)
			return (result);
		i++;
	}
	return (i);
}
