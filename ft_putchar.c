/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:52:55 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/10 11:59:26 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(int fd, char *str)
{
	int	len;

	if (!str)
		return (ft_putstr(fd, "(null)"));
	len = 0;
	while (*str)
		len += ft_putchar(fd, *str++);
	return (len);
}
