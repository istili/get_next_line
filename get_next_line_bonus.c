/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istili <istili@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 08:46:14 by istili            #+#    #+#             */
/*   Updated: 2023/12/08 23:48:00 by istili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*check(char *bufr, int fd)
{
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0
		|| BUFFER_SIZE > INT_MAX || read(fd, bufr, 0) < 0)
		return (free(bufr), bufr = NULL, NULL);
	if (!bufr)
		bufr = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!bufr)
		return (NULL);
	return (bufr);
}

char	*get_next_line(int fd)
{
	static char		*bufr[OPEN_MAX];
	char			*line;
	int				i;

	bufr[fd] = check(bufr[fd], fd);
	if (!bufr[fd])
		return (NULL);
	line = ft_strjoin(NULL, bufr[fd]);
	if (!line)
		return (free(bufr[fd]), bufr[fd] = NULL, NULL);
	if (check_str(bufr[fd]) != 0)
		return (line);
	i = 1;
	while (i > 0)
	{
		i = read(fd, bufr[fd], BUFFER_SIZE);
		if (i == -1 || (i == 0 && line[0] == '\0'))
			return (free(bufr[fd]), bufr[fd] = NULL, free(line), NULL);
		line = ft_strjoin(line, bufr[fd]);
		if (!line)
			return (free(bufr[fd]), bufr[fd] = NULL, NULL);
		if (check_str(bufr[fd]) != 0)
			return (line);
	}
	return (line);
}
