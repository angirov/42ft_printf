/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:23:32 by vangirov          #+#    #+#             */
/*   Updated: 2022/02/03 20:58:20 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(uint64_t num, char *hexbase)
{
	int	len;

	len = 0;
	if (num < 16)
		return (ft_putchar(hexbase[num]));
	len += ft_puthex(num / 16, hexbase);
	len += ft_puthex(num % 16, hexbase);
	return (len);
}

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (ft_putstr(NULL_OUTPUT));
	return (ft_putstr("0x") + ft_puthex((uint64_t)ptr, "0123456789abcdef"));
}

// #include <stdio.h>
// int	main()
// {
// 	char	*ptr = "a";
// 	// printf("\n%zd\n", ft_putint(-2147483648));
// 	printf("\n%zd\n", ft_puthex(4294967295, "0123456789abcdef"));
// 	printf("\n%zd\n", ft_putprt(ptr));
// 	printf("%p", ptr);
// }
