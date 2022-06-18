/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:57:16 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/16 19:12:13 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# if BUFFER_SIZE <= 0
#  define BUFFER_SIZE 128
# endif

char	*ft_append(char *line, char buffer);
char	*ft_read(int fd, char *buffer);
char	*ft_getline(int fd);
char	*get_next_line(int fd);

#endif
