/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_here_doc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phuocngu <phuocngu@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:35:37 by phuocngu          #+#    #+#             */
/*   Updated: 2025/01/18 12:00:02 by phuocngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	read_here_doc(t_pipex *pipex)
{
	char	*line;
	size_t	len_limiter;
	int		pipeline_fd[2];

	create_pipe(pipeline_fd);
	len_limiter = ft_strlen(pipex->limiter);
	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strncmp(line, pipex->limiter, len_limiter)
			&& (line[len_limiter] == '\n' || line[len_limiter] == '\0'))
		{
			free(line);
			break ;
		}
		write(pipeline_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipeline_fd[1]);
	pipex->prev_fd = pipeline_fd[0];
}
