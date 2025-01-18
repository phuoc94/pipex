/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:27:36 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/18 18:37:02 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

const char	*find_quote_end(const char *start, char quote)
{
	const char	*end;

	end = ft_strchr(start, quote);
	if (!end)
	{
		ft_perror("Error", "Unmatched quotes in command");
		exit(EXIT_FAILURE);
	}
	return (end);
}

const char	*find_token_end(const char *start)
{
	const char	*end;

	end = start;
	while (*end && !ft_isspace(*end))
		end++;
	return (end);
}

char	*create_token(const char *start, size_t len)
{
	char	*token;

	token = ft_substr(start, 0, len);
	if (!token)
	{
		ft_perror("Memory allocation failed", "ft_substr");
		exit(EXIT_FAILURE);
	}
	return (token);
}
