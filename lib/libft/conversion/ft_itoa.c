/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:59:02 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:34:40 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static size_t	ft_intlen(int n)
{
	size_t	len;
	long	temp;

	len = 0;
	temp = n;
	if (temp <= 0)
	{
		len = 1;
		temp = -temp;
	}
	while (temp > 0)
	{
		len++;
		temp /= 10;
	}
	return (len);
}

/**
 * @file ft_itoa.c
 * @brief Converts an integer to a null-terminated string.
 *
 * This function takes an integer value and converts it to a string
 * representation. The resulting string is dynamically allocated and
 * must be freed by the caller.
 *
 * @param n The integer to be converted.
 * @return A pointer to the null-terminated string representing the integer,
 *         or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	long	temp;

	len = ft_intlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	temp = n;
	if (temp < 0)
		temp = -temp;
	while (len > 0)
	{
		str[--len] = (temp % 10) + '0';
		temp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
