/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:17:41 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:41:33 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprint.c
 * @brief Checks if a character is printable.
 *
 * This function checks if the given character is a printable character,
 * including space. Printable characters are those in the range of 32 to 126
 * in the ASCII table.
 *
 * @param c The character to be checked.
 * @return 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
