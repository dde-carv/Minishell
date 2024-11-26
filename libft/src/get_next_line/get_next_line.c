/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:56:00 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/10 17:00:03 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX + 1][BUFFER_SIZE + 1];
	char		*line;
	size_t		len;
	size_t		len1;
	int			nl;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = NULL;
	nl = 0;
	while (!nl && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		line = ft_gnl_strjoin(line, buffer[fd]);
		len = 0;
		len1 = 0;
		while (buffer[fd][len])
		{
			if (nl)
				buffer[fd][len1++] = buffer[fd][len];
			if (buffer[fd][len] == '\n')
				nl = 1;
			buffer[fd][len++] = 0;
		}
	}
	return (line);
}
