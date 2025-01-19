/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:10:51 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:37:57 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_hex(unsigned long n, int uppercase, int fd)
{
	const char	*hex;
	int			len;
	int			result;

	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	len = 0;
	if (n >= 16)
	{
		result = print_hex((n / 16), uppercase, fd);
		if (result == -1)
			return (result);
		len += result;
	}
	result = write(fd, &hex[n % 16], 1);
	if (result == -1)
		return (result);
	len += result;
	return (len);
}

int	ft_print_ptr(void *ptr, int fd)
{
	int	len;
	int	result;

	if (!ptr)
		return (write(1, "(nil)", 5));
	result = 0;
	len = 0;
	result = write(1, "0x", 2);
	if (result == -1)
		return (result);
	len += result;
	result = print_hex((unsigned long)ptr, 0, fd);
	if (result == -1)
		return (result);
	len += result;
	return (len);
}
