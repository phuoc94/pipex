/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:36:29 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 15:15:44 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_minval(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * @brief Concatenates the string `src` to the end of `dst` ensuring that the
 *        total length of the concatenated string does not exceed `size` bytes
 *        (including the null-terminator).
 *
 * @param dst The destination buffer to which the string `src` will be
 *        concatenated.
 * @param src The source string to be concatenated to `dst`.
 * @param size The total size of the destination buffer `dst`.
 *
 * @return The total length of the string it tried to create, i.e., the initial
 *         length of `dst` plus the length of `src`. If the return value is
 *         greater than or equal to `size`, truncation occurred.
 *
 * @note If `dst` is NULL and `size` is 0, the function returns 0.
 *       If `size` is less than or equal to the length of `dst`, the function
 *       returns the length of `src` plus `size`.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && size == 0)
		return (0);
	dst_len = ft_minval(ft_strlen(dst), size);
	src_len = ft_strlen(src);
	if (size == dst_len)
		return (src_len + size);
	if (src_len < (size - dst_len))
		ft_memcpy((&dst[dst_len]), src, (src_len + 1));
	else
	{
		ft_memcpy((&dst[dst_len]), src, (size - dst_len - 1));
		dst[size - 1] = '\0';
	}
	return (dst_len + src_len);
}
