/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:16:03 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:01:26 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_isnumber.c
 * @brief Checks if a given string represents a valid number.
 *
 * This function checks if the input string `s` represents a valid number.
 * A valid number can optionally start with a '+' or '-' sign followed by digits.
 *
 * @param s The input string to check.
 * @return 1 if the string represents a valid number, 0 otherwise.
 */
int	ft_isnumber(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
