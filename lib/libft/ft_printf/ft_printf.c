/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:59:02 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:43:31 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_format(char c, va_list *args, int fd)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int), fd));
	else if (c == 's')
		return (ft_print_str(va_arg(*args, char *), fd));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *), fd));
	else if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int), fd));
	else if (c == 'u')
		return (ft_print_nbr(va_arg(*args, unsigned int), fd));
	else if (c == 'x')
		return (print_hex(va_arg(*args, unsigned int), 0, fd));
	else if (c == 'X')
		return (print_hex(va_arg(*args, unsigned int), 1, fd));
	else if (c == '%')
		return (ft_print_char('%', fd));
	else
		return (ft_print_char(c, fd));
}

/**
 * ft_printf_fd
	- Custom implementation of printf that writes to a file descriptor.
 * @fd: The file descriptor where the output should be written.
 * @str: The format string containing the text to be written.
 * @...: Additional arguments specifying the values to be printed.
 *
 * This function processes the format string and writes the corresponding
 * values to the specified file descriptor. It supports a subset of the
 * standard printf format specifiers. The function returns the total number
 * of characters written, or -1 if an error occurs.
 *
 * Return: The total number of characters written, or -1 if an error occurs.
 */
int	ft_printf_fd(int fd, const char *str, ...)
{
	int		i;
	va_list	args;
	int		result_len;
	int		result;

	i = 0;
	result_len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			result = handle_format(str[i + 1], &args, fd);
			i++;
		}
		else
			result = ft_print_char(str[i], fd);
		if (result == -1)
			return (result);
		result_len += result;
		i++;
	}
	va_end(args);
	return (result_len);
}

/**
 * ft_printf - Custom implementation of the printf function.
 * @str: The format string containing the text to be written to stdout.
 *       It can optionally contain format specifiers that will be replaced
 *       by the values specified in the additional arguments.
 * @...: Additional arguments specifying the values to be printed according
 *       to the format specifiers in the format string.
 *
 * This function processes the format string and prints the corresponding
 * values to stdout. It supports a subset of the standard printf format
 * specifiers. The function returns the total number of characters printed,
 * or -1 if an error occurs.
 *
 * Return: The total number of characters printed, or -1 if an error occurs.
 */
int	ft_printf(const char *str, ...)
{
	int		result;
	va_list	args;

	va_start(args, str);
	result = ft_printf_fd(1, str, args);
	va_end(args);
	return (result);
}
