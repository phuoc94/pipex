/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:26:07 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:59:04 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @file ft_strlen.c
 * @brief Implementation of the ft_strlen function.
 *
 * This file contains the implementation of the ft_strlen function, which
 * calculates the length of a null-terminated string.
 */

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * This function takes a pointer to a null-terminated string as input and
 * returns the number of characters in the string, excluding the null
 * terminator.
 *
 * @param s Pointer to the null-terminated string.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
