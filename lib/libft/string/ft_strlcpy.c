/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:30 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:16:07 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src
 *        to dst, NUL-terminating the result.
 *
 * @param dst The destination buffer where the content is to be copied.
 * @param src The source string to be copied.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create, which is the
 *         length of src.
 *
 * @note If size is 0, the function returns the length of src and does not copy
 *       anything. If the length of src is greater than or equal to size, the
 *       destination string will not be NUL-terminated.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
