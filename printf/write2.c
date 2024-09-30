/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:58:44 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/04 18:35:49 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlenght(char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	ft_putnbrbase(long n, char *base)
{
	long	nbr;
	size_t	count;
	long	lenght;

	lenght = ft_strlenght(base);
	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		count++;
	}
	if (nbr >= lenght)
	{
		count += ft_putnbrbase(nbr / lenght, base);
	}
	write(1, &base[nbr % lenght], 1);
	count++;
	return (count);
}

int	ft_putptrbase(unsigned long n, char *base)
{
	size_t	length;
	size_t	count;

	length = ft_strlenght(base);
	count = 0;
	if (n >= length)
		count += ft_putnbrbase(n / length, base);
	write(1, &base[n % length], 1);
	count++;
	return (count);
}
