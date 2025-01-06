/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:18:06 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:01:16 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

/**
 * @file ft_isint.c
 * @brief Checks if a given long integer can be represented as an int.
 *
 * This function takes a long integer as input and checks whether it falls
 * within the range of values that can be represented by an int type.
 *
 * @param n The long integer to be checked.
 * @return 1 if the integer can be represented as an int, 0 otherwise.
 */
int	ft_isint(long n)
{
	return (n >= INT_MIN && n <= INT_MAX);
}
