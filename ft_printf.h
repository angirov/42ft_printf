/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 18:56:08 by vangirov          #+#    #+#             */
/*   Updated: 2022/02/03 20:56:32 by vangirov         ###   ########.fr       */
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
int	ft_convert(va_list ap, char cs);

int	ft_putchar(char c);
int	ft_putstr(char *str);

int	ft_putint(int32_t num);
int	ft_putuint(uint32_t num);

int	ft_puthex(uint64_t num, char *hexbase);
int	ft_putptr(void *ptr);

#endif
