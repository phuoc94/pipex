/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:10:51 by phuocngu          #+#    #+#             */
/*   Updated: 2024/11/14 17:50:46 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_hex(unsigned long n, int uppercase)
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
		result = print_hex((n / 16), uppercase);
		if (result == -1)
			return (result);
		len += result;
	}
	result = write(1, &hex[n % 16], 1);
	if (result == -1)
		return (result);
	len += result;
	return (len);
}

int	ft_print_ptr(void *ptr)
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
	result = print_hex((unsigned long)ptr, 0);
	if (result == -1)
		return (result);
	len += result;
	return (len);
}
