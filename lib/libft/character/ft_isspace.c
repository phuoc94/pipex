/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:56:16 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:41:48 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isspace.c
 * @brief Checks if a character is a whitespace character.
 *
 * This function checks if the given character is a whitespace character.
 * Whitespace characters include: space (' '), horizontal tab ('\t'),
 * newline ('\n'), vertical tab ('\v'), form feed ('\f'), and carriage
 * return ('\r').
 *
 * @param c The character to check.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}
