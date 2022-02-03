/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:53:21 by vangirov          #+#    #+#             */
/*   Updated: 2022/02/03 19:21:45 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int32_t num)
{
	int	len;

	len = 0;
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	if (num < 0)
	{
		len += ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
	{
		len += ft_putint(num / 10);
		len += ft_putint(num % 10);
	}
	if (num < 10)
		len += ft_putchar(num + '0');
	return (len);
}

int	ft_putuint(uint32_t num)
{
	int	len;

	len = 0;
	if (num >= 10)
	{
		len += ft_putuint(num / 10);
		len += ft_putuint(num % 10);
	}
	if (num < 10)
		len += ft_putchar(num + '0');
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	printf("\n%zd\n", ft_putint(-2147483648));
// 	printf("\n%zd\n", ft_putuint(4294967295));
// }
