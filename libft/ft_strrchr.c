/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:49:53 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/10 23:18:34 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_start;

	s_start = s;
	s += ft_strlen(s);
	if (!c)
		return ((char *)s);
	while (--s >= s_start)
	{
		if (*s == (char) c)
			return ((char *)s);
	}
	return (NULL);
}
