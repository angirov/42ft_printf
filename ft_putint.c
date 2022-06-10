/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:53:21 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/10 11:53:10 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int fd, int32_t num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (ft_putstr(fd, "-2147483648"));
	if (num < 0)
	{
		len += ft_putchar(fd, '-');
		num *= -1;
	}
	if (num >= 10)
	{
		len += ft_putint(fd, num / 10);
		len += ft_putint(fd, num % 10);
	}
	if (num < 10)
		len += ft_putchar(fd, num + '0');
	return (len);
}

int	ft_putuint(int fd, uint32_t num)
{
	int	len;

	len = 0;
	if (num >= 10)
	{
		len += ft_putuint(fd, num / 10);
		len += ft_putuint(fd, num % 10);
	}
	if (num < 10)
		len += ft_putchar(fd, num + '0');
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	printf("\n%zd\n", ft_putint(fd, -2147483648));
// 	printf("\n%zd\n", ft_putuint(fd, 4294967295));
// }
