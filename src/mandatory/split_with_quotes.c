/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_with_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:03:36 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/19 15:56:33 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static char	*extract_token(const char **start_ptr)
{
	const char	*start;
	const char	*end;
	char		*token;
	char		quote;
	size_t		len;

	start = *start_ptr;
	if (*start == '"' || *start == '\'')
	{
		quote = *start;
		start++;
		end = find_quote_end(start, quote);
	}
	else
	{
		end = find_token_end(start);
	}
	len = end - start;
	token = create_token(start, len);
	if (*end == '"' || *end == '\'')
		*start_ptr = end + 1;
	else
		*start_ptr = end;
	return (token);
}

static void	skip_whitespace(const char **start_ptr)
{
	while (ft_isspace(**start_ptr))
		(*start_ptr)++;
}

static char	**add_token_to_args(char **args, int *count, char *token)
{
	char	**new_args;
	int		i;

	new_args = malloc(sizeof(char *) * (*count + 2));
	if (!new_args)
	{
		free(args);
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < *count)
	{
		new_args[i] = args[i];
		i++;
	}
	new_args[*count] = token;
	new_args[*count + 1] = NULL;
	free(args);
	(*count)++;
	return (new_args);
}

char	**split_with_quotes(const char *cmd)
{
	char		**args;
	int			count;
	const char	*start = cmd;
	char		*token;

	args = malloc(sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	args[0] = NULL;
	count = 0;
	while (*start)
	{
		skip_whitespace(&start);
		if (*start == '\0')
			break ;
		token = extract_token(&start);
		args = add_token_to_args(args, &count, token);
	}
	return (args);
}
