/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:12:51 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/11 16:01:46 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
