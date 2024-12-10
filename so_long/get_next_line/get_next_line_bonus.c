/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdel-f <rabdel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:59:03 by rabdel-f          #+#    #+#             */
/*   Updated: 2024/06/27 16:29:45 by rabdel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	re;
	char	*tmp;

	re = 1;
	while (re > 0)
	{
		re = read(fd, buffer, BUFFER_SIZE);
		if (re == -1)
		{
			free (left_c);
			return (NULL);
		}
		else if (re == 0)
			break ;
		buffer[re] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*set_line(char *line_buffer)
{
	char	*left_c;
	int		i;

	i = 0;
	while (line_buffer[i] != '\0' && line_buffer[i] != '\n')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c[MAX_FD];
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (left_c[fd]);
		free (buffer);
		left_c[fd] = 0;
		buffer = 0;
		return (0);
	}
	if (!buffer)
		return (0);
	line = fill_line_buffer(fd, left_c[fd], buffer);
	free(buffer);
	buffer = 0;
	if (!line)
		return (0);
	left_c[fd] = set_line(line);
	return (line);
}
