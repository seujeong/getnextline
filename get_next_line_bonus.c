/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 00:53:45 by marvin            #+#    #+#             */
/*   Updated: 2021/01/06 00:53:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_newline(char *temp)
{
	int			index;

	index = 0;
	while (temp[index])
	{
		if (temp[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

int	split_newline(char **line_temp, char **line, int newline_index)
{
	char		*split_temp;
	int			len_after_newline;

	(*line_temp)[newline_index] = '\0';
	*line = ft_strdup(*line_temp);
	len_after_newline = ft_strlen(line_temp[newline_index + 1]);
	if (len_after_newline == 0)
	{
		free(*line_temp);
		*line_temp = 0;
		return (1);
	}
	split_temp = ft_strdup(line_temp[newline_index + 1]);
	free(*line_temp);
	*line_temp = split_temp;
	return (1);
}

int	return_end(char **line_temp, char **line, int read_byte)
{
	int			newline_index;

	if (read_byte < 0)
		return (-1);
	if (*line_temp && (newline_index = find_newline(*line_temp)) >= 0)
		return (split_line(line_temp, line, newline_index));
	else if (*line_temp)
	{
		*line = *line_temp;
		*line_temp = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*line_temp[OPEN_MAX];
	char		*buf;
	int			read_byte;
	int			newline_index;

	if ((fd < 0) || (line == NULL) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_byte] = '\0';
		line_temp[fd] = ft_strjoin(line_temp[fd], buf);
		if ((newline_index = find_newline(line_temp[fd]) >= 0))
			return (split_newline(&line_temp[fd], line, newline_index));
	}
	return (return_end(&line_temp[fd], line, read_byte));
}
