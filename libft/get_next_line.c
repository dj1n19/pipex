/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:37:11 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/03 12:46:55 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	int		res;

	res = read(fd, buffer, 1);
	if (res < 0)
		return (NULL);
	if (res == 0)
		*buffer = -1;
	return (buffer);
}

char	*ft_getline(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*read;
	static char	*line;

	line = NULL;
	while (1)
	{
		read = ft_read(fd, buffer);
		if (!read)
			return (NULL);
		else if (*read != 10 && *read != -1)
			line = ft_append(line, *read);
		else if (*read == 10)
			return (ft_append(line, *read));
		else if (*read == -1 && line)
			return (line);
		else if (*read == -1 && !line)
			return (NULL);
	}
}

char	*get_next_line(int fd)
{
	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	return (ft_getline(fd));
}
