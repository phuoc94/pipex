/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:06:38 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:14:21 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_strmapi - Applies a function to each character of a string to create a
 * new string.
 * @s: The input string.
 * @f: The function to apply to each character of the string. It takes an
 * unsigned int as the index of the character and a char as the character
 * itself, and returns a char which is the result of the function.
 *
 * This function allocates (with malloc) and returns a new string, which is
 * the result of applying the function 'f' to each character of the string
 * 's'. The function 'f' is applied to each character of the string 's' with
 * its index as the first argument. If the allocation fails, the function
 * returns NULL.
 *
 * Return: The new string created from the successive applications of 'f'.
 *         NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	len = ft_strlen(s);
	i = 0;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
