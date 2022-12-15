/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:18:12 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/15 23:27:59 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(va_list params, const char format)
{
	int	written;

	written = 0;
	if (format == 'c')
		written = ft_putchr(va_arg(params, int));
	else if (format == 's')
		written = ft_putstr(va_arg(params, char *));
	else if (format == 'p')
		written = ft_putptr(va_arg(params, unsigned long long));
	else if (format == 'i' || format == 'd')
		written = ft_putnbr(va_arg(params, int));
	else if (format == 'u')
		written = ft_putuint(va_arg(params, unsigned int));
	else if (format == 'x')
		written = ft_puthex(va_arg(params, unsigned long long));
	else if (format == 'X')
		written = ft_putuphex(va_arg(params, unsigned long long));
	else if (format == '%')
		written = ft_putchr('%');
	return (written);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		i;
	int		written;

	i = 0;
	written = 0;
	va_start(params, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			written += ft_format(params, str[i + 1]);
			i += 1;
		}
		else
			written += ft_putchr(str[i]);
		i++;
	}
	va_end(params);
	return (written);
}
