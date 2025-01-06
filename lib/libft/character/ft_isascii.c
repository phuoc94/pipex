/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:57:32 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:32:59 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isascii.c
 * @brief Checks if a given character is an ASCII character.
 *
 * This function checks whether the given integer `c` is an ASCII character.
 * ASCII characters are those with values between 0 and 127 inclusive.
 *
 * @param c The integer to be checked.
 * @return 1 if `c` is an ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
