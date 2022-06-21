/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:09:22 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/20 13:09:25 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*new_str;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_str = malloc(1);
		if (!new_str)
			return (NULL);
		*new_str = 0;
		return (new_str);
	}
	s += start;
	if (ft_strlen(s) > len)
		new_str = malloc(len + 1);
	else
		new_str = malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	while (*s && len--)
		new_str[i++] = *s++;
	new_str[i] = 0;
	return (new_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	if (!*s1 || !*s2)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*new_str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	i = 0;
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	new_str[i] = 0;
	return (new_str);
}
