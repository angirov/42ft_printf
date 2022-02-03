/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:58:47 by vangirov          #+#    #+#             */
/*   Updated: 2022/02/03 21:24:22 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert(va_list ap, char cs)
{
	int	len;

	len = 0;
	if (cs == 'c')
		len += ft_putchar(va_arg(ap, int32_t));
	if (cs == 's')
		len += ft_putstr(va_arg(ap, char *));
	if (cs == 'i' || cs == 'd')
		len += ft_putint(va_arg(ap, int32_t));
	if (cs == 'u')
		len += ft_putuint(va_arg(ap, uint32_t));
	if (cs == 'p')
		len += ft_putptr(va_arg(ap, void *));
	if (cs == 'x')
		len += ft_puthex(va_arg(ap, uint32_t), "0123456789abcdef");
	if (cs == 'X')
		len += ft_puthex(va_arg(ap, uint32_t), "0123456789ABCDEF");
	if (cs == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			len += ft_convert(ap, *++fmt);
			fmt++;
		}
		else
			len += write(1, &(*fmt++), 1);
	}
	va_end(ap);
	return (len);
}

// #include <stdio.h>
// int	main()
// {
// 	ft_printf("%s", NULL);
// }