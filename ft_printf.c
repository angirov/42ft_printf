/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:58:47 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/10 12:09:28 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(int fd, va_list ap, char cs)
{
	int	len;

	len = 0;
	if (cs == 'c')
		len += ft_putchar(fd, va_arg(ap, int32_t));
	if (cs == 's')
		len += ft_putstr(fd, va_arg(ap, char *));
	if (cs == 'i' || cs == 'd')
		len += ft_putint(fd, va_arg(ap, int32_t));
	if (cs == 'u')
		len += ft_putuint(fd, va_arg(ap, uint32_t));
	if (cs == 'p')
		len += ft_putptr(fd, va_arg(ap, void *));
	if (cs == 'x')
		len += ft_puthex(fd, va_arg(ap, uint32_t), "0123456789abcdef");
	if (cs == 'X')
		len += ft_puthex(fd, va_arg(ap, uint32_t), "0123456789ABCDEF");
	if (cs == '%')
		len += ft_putchar(fd, '%');
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;
	int		fd;

	fd = 1;
	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			len += ft_convert(fd, ap, *++fmt);
			fmt++;
		}
		else
			len += write(fd, &(*fmt++), 1);
	}
	va_end(ap);
	return (len);
}

int	ft_fdprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			len += ft_convert(fd, ap, *++fmt);
			fmt++;
		}
		else
			len += write(fd, &(*fmt++), 1);
	}
	va_end(ap);
	return (len);
}

// #include <stdio.h>
// int	main()
// {
// 	ft_printf(int fd, "%s", NULL);
// }