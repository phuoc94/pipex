/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:37:37 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:48:18 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalnum.c
 * @brief Checks if the given character is alphanumeric.
 *
 * This function checks if the given character is either an alphabetic letter
 * (a-z, A-Z) or a digit (0-9).
 *
 * @param c The character to be checked.
 * @return Non-zero value if the character is alphanumeric, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'));
}
