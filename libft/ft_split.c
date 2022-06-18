/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:48:58 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/14 22:31:20 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c)
			{
				if (!*s)
					return (count);
				s++;
			}
		}
		s++;
	}
	return (count);
}

static char	*ft_word_extract(const char *s, char c)
{
	char		*word;
	const char	*start;
	int			i;

	start = s;
	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	word = ft_substr(start, 0, i);
	return (word);
}

static void	ft_free_strings_array(char **strings_array)
{
	while (*strings_array)
		free(*strings_array++);
	free(strings_array);
}

char	**ft_split(char const *s, char c)
{
	char	**strings_array;
	char	**sa_start;

	if (!s)
		return (NULL);
	strings_array = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!strings_array)
		return (NULL);
	sa_start = strings_array;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		*strings_array = ft_word_extract(s, c);
		if (!*strings_array)
		{
			ft_free_strings_array(sa_start);
			return (NULL);
		}
		s += ft_strlen(*strings_array++);
	}
	*strings_array = NULL;
	return (sa_start);
}
