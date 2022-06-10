/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:23:32 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/10 12:00:47 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int fd, uint64_t num, char *hexbase)
{
	int	len;

	len = 0;
	if (num < 16)
		return (ft_putchar(fd, hexbase[num]));
	len += ft_puthex(fd, num / 16, hexbase);
	len += ft_puthex(fd, num % 16, hexbase);
	return (len);
}

int	ft_putptr(int fd, void *ptr)
{
	if (!ptr)
		return (ft_putstr(fd, NULL_OUTPUT));
	return (ft_putstr(fd, "0x") + ft_puthex(fd, (uint64_t)ptr, "0123456789abcdef"));
}

// #include <stdio.h>
// int	main()
// {
// 	char	*ptr = "a";
// 	// printf("\n%zd\n", ft_putint(fd, -2147483648));
// 	printf("\n%zd\n", ft_puthex(fd, 4294967295, "0123456789abcdef"));
// 	printf("\n%zd\n", ft_putprt(fd, ptr));
// 	printf("%p", ptr);
// }
