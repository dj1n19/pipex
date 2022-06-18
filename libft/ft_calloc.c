/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:50:48 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/11 13:38:39 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated_mem;

	if (count == 0)
		count = 1;
	if (size == 0)
		size = 1;
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	allocated_mem = malloc(count * size);
	if (!allocated_mem)
		return (NULL);
	ft_bzero(allocated_mem, count * size);
	return (allocated_mem);
}
