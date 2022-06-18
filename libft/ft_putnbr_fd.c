/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:28:08 by bgenie            #+#    #+#             */
/*   Updated: 2022/04/12 14:46:59 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

long int	ft_to_char(long int nbr)
{
	if (nbr < 0)
		nbr = -nbr % 10 + 48;
	else
		nbr = nbr % 10 + 48;
	return (nbr);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		digits[11];
	long int	nbr;
	int			i;

	if (fd < 0)
		return ;
	i = ft_nbr_size(n);
	if (i == 0)
	{
		digits[0] = 48;
		digits[1] = 0;
	}
	else
		digits[i--] = 0;
	nbr = (long int) n;
	if (nbr < 0)
		write(fd, "-", 1);
	while (nbr != 0)
	{
		digits[i--] = ft_to_char(nbr);
		nbr /= 10;
	}
	ft_putstr_fd(digits, fd);
}
