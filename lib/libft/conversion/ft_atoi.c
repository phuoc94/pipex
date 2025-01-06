/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:08 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:34:15 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_atoi.c
 * @brief Converts a string to an integer.
 *
 * This function takes a string representing a number and converts it to an
 * integer. It handles optional leading whitespace, an optional sign, and
 * numeric digits.
 *
 * @param nptr The string to be converted to an integer.
 * @return The converted integer value.
 *
 * The function skips any leading whitespace characters as determined by
 * ft_isspace(). It then checks for an optional '+' or '-' sign to determine
 * the sign of the resulting integer. Finally, it processes the numeric digits
 * and constructs the integer value.
 *
 * Example usage:
 * @code
 * int value = ft_atoi("  -123");
 * // value will be -123
 * @endcode
 */
int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
