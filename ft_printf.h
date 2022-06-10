/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:56:08 by vangirov          #+#    #+#             */
/*   Updated: 2022/06/10 12:04:57 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# if defined(__linux__)
#  define NULL_OUTPUT "(nil)"
# elif defined(__APPLE__)
#  define NULL_OUTPUT "0x0"
# endif

int	ft_printf(const char *fmt, ...);
int	ft_fdprintf(int fd, const char *fmt, ...);
int	ft_convert(int fd, va_list ap, char cs);

int	ft_putchar(int fd, char c);
int	ft_putstr(int fd, char *str);

int	ft_putint(int fd, int32_t num);
int	ft_putuint(int fd, uint32_t num);

int	ft_puthex(int fd, uint64_t num, char *hexbase);
int	ft_putptr(int fd, void *ptr);

#endif
