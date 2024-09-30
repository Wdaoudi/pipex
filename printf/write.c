/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:32:10 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/07/08 13:58:57 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		return (ft_putstr("(null)"));
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(const int n)
{
	long	nbr;
	long	i;

	i = 0;
	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr);
		i++;
	}
	else if (nbr >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else if (nbr < 10)
	{
		write(1, &nbr, 1);
		i++;
	}
	return (i);
}

// int main() {
//     // Test cases for ft_putnbrbase
//     printf("Decimal (base 10):\n");
//     ft_putnbrbase(12345, "0123456789");
//     printf("\nExpected output: 12345\n\n");

//     printf("Hexadecimal (base 16):\n");
//     ft_putnbrbase(255, "0123456789abcdef");
//     printf("\nExpected output: ff\n\n");

//     printf("Binary (base 2):\n");
//     ft_putnbrbase(5, "01");
//     printf("\nExpected output: 101\n\n");

//     printf("Octal (base 8):\n");
//     ft_putnbrbase(64, "01234567");
//     printf("\nExpected output: 100\n\n");

//     printf("Negative number (base 10):\n");
//     ft_putnbrbase(-12345, "0123456789");
//     printf("\nExpected output: -12345\n");

//     return (0);
// }