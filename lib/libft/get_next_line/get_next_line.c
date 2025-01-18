/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:46:51 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/18 13:05:29 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*extract_line(char *buffer)
{
	char	*newline_pos;
	size_t	len;
	char	*line;

	newline_pos = ft_strchr(buffer, '\n');
	if (!buffer[0])
		return (0);
	if (newline_pos)
	{
		len = newline_pos - buffer + 1;
		line = ft_substr(buffer, 0, len);
		ft_strlcpy(buffer, newline_pos + 1, BUFFER_SIZE + 1);
		return (line);
	}
	line = ft_substr(buffer, 0, ft_strlen(buffer));
	buffer[0] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		temp_buffer[BUFFER_SIZE + 1];
	int			bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (ft_strchr(buffer, '\n'))
		return (extract_line(buffer));
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	while (!ft_strchr(buffer, '\n') && (bytes_read) > 0)
	{
		temp_buffer[bytes_read] = 0;
		ft_strlcat(buffer, temp_buffer, BUFFER_SIZE + 1);
	}
	line = extract_line(buffer);
	if (!line || !line[0])
	{
		free(line);
		return (0);
	}
	return (line);
}
