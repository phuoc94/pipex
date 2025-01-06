/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:38:28 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:19:22 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_char_to_digit(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (-1);
}

static size_t	ft_skip_whitespace(const char *nptr)
{
	size_t	i;

	i = 0;
	while (ft_isspace(nptr[i]))
	{
		i++;
	}
	return (i);
}

static int	ft_parse_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-')
	{
		sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	return (sign);
}

/**
 * @brief Converts the initial part of the string in nptr to a long integer
 *        value according to the given base.
 *
 * @param nptr Pointer to the null-terminated string to be interpreted.
 * @param endptr Pointer to a pointer to character. If endptr is not NULL,
 *               a pointer to the character after the last character used in
 *               the conversion is stored in the location referenced by endptr.
 * @param base Base of the number in the string. Must be between 2 and 36
 *             inclusive, or the special value 0.
 *
 * @return The converted value as a long integer. If no valid conversion
 *         could be performed, returns 0.
 *         If base is invalid, returns 0 and sets endptr to nptr.
 */
long	ft_strtol(const char *nptr, char **endptr, int base)
{
	size_t	i;
	int		sign;
	long	result;
	int		digit;

	if (base < 2 || base > 36)
	{
		if (endptr)
			*endptr = (char *)nptr;
		return (0);
	}
	i = ft_skip_whitespace(nptr);
	nptr += i;
	sign = ft_parse_sign(&nptr);
	result = 0;
	digit = ft_char_to_digit(*nptr);
	while (digit >= 0 && digit < base)
	{
		result = result * base + digit;
		nptr++;
		digit = ft_char_to_digit(*nptr);
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}
