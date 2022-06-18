/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:35:06 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/16 19:11:15 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *line, char buffer)
{
	char	*nline;
	size_t	size;
	int		i;

	i = 0;
	size = ft_strlen(line);
	nline = (char *) malloc(sizeof(char) * (size + 2));
	if (!nline)
		return (NULL);
	while (line && line[i])
	{
		nline[i] = line[i];
		i++;
	}
	nline[i] = buffer;
	nline[i + 1] = 0;
	if (line)
		free(line);
	return (nline);
}
