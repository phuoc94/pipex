/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:12:35 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/06 14:33:26 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static double	parse_integer_part(const char *str)
{
	int		i;
	double	result;

	i = 0;
	result = 0.0;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

static double	parse_fractional_part(const char *str)
{
	int		i;
	double	fraction;
	double	divisor;

	i = 0;
	fraction = 0.0;
	divisor = 10.0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			fraction += (str[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
	}
	return (fraction);
}

/**
 * @brief Converts a string to a double.
 *
 * This function converts the initial portion of the string pointed to by str
 * to a double representation. It handles optional leading whitespace, an
 * optional sign, and both integer and fractional parts.
 *
 * @param str The string to be converted.
 * @return The converted double value.
 */
double	ft_atof(const char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = parse_integer_part(str);
	result += parse_fractional_part(str);
	return (result * sign);
}
