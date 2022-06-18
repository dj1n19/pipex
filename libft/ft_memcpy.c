/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:11:55 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/11 14:05:25 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_bytes;
	const unsigned char	*src_bytes;

	if (!src && !dst)
		return (NULL);
	dst_bytes = dst;
	src_bytes = src;
	while (n--)
		*dst_bytes++ = *src_bytes++;
	return (dst);
}
