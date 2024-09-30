/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaoudi- <wdaoudi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:21:28 by wdaoudi-          #+#    #+#             */
/*   Updated: 2024/09/17 13:53:54 by wdaoudi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptrdef(long a, char *base)
{
	if (a == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putptrbase(a, base));
}

int	type(va_list args, const char c, size_t len)
{
	if (c == '%')
		len += ft_putchar('%');
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len += ptrdef((long)va_arg(args, void *), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		len += ft_putnbrbase(va_arg(args, int), "0123456789");
	else if (c == 'u')
		len += ft_putnbrbase(va_arg(args, unsigned int), "0123456789");
	else if (c == 'x')
		len += ft_putnbrbase(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_putnbrbase(va_arg(args, unsigned int), "0123456789ABCDEF");
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len = type(args, format[i + 1], len);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

/*int	main(void)
{
	size_t	t = 0;
	ft_printf("%c",'A');
	ft_printf("%s\n", "Hello, World!");
	t = ft_printf("%p\n", (void*)LONG_MIN);
	printf("%zu\n", t);
	t = ft_printf("%p\n", (void*)LONG_MAX);
	printf("%zu\n", t);
	ft_printf("%d\n", 123);
	ft_printf("%u\n", 123);
	ft_printf("%x\n", 42);
	ft_printf("%X\n", 42);
	ft_printf("%%\n");
	// printf("%c\n", 'A');
	// printf("%s\n", "Hello, World!");
	t = printf("%p\n", (void*)LONG_MIN);
	printf("%zu\n", t);
	t = printf("%p\n", (void*)LONG_MAX);
	printf("%zu\n", t);
	// printf("%d\n", 123);
	// printf("%u\n", 123);
	// printf("%x\n", 255);
	// printf("%X\n", 255);
	// printf("%%\n");

	return (0);
}*/