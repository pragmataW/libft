/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:24:59 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/15 23:28:41 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long long nbr)
{	
	int	chr;

	chr = 2;
	ft_putstr("0x");
	chr += ft_putptrhex(nbr);
	return (chr);
}

int	ft_counthex(unsigned long long nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_putptrhex(unsigned long long nbr)
{
	char	*arr;
	char	*res;
	size_t	len;
	int		chr;

	len = ft_counthex(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	arr = ft_strdup("0123456789abcdef");
	while ((nbr / 16) != 0)
	{
		res[len - 1] = arr[nbr % 16];
		len--;
		nbr /= 16;
	}
	res[0] = arr[nbr];
	chr = ft_strlen(res);
	ft_putstr(res);
	free(res);
	free(arr);
	return (chr);
}

int	ft_puthex(unsigned int nbr)
{
	char	*arr;
	char	*res;
	size_t	len;
	int		chr;

	len = ft_counthex(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	arr = ft_strdup("0123456789abcdef");
	while ((nbr / 16) != 0)
	{
		res[len - 1] = arr[nbr % 16];
		len--;
		nbr /= 16;
	}
	res[0] = arr[nbr];
	chr = ft_strlen(res);
	ft_putstr(res);
	free(res);
	free(arr);
	return (chr);
}

int	ft_putuphex(unsigned int nbr)
{
	char	*arr;
	char	*res;
	size_t	len;
	int		chr;

	len = ft_counthex(nbr);
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len] = '\0';
	arr = ft_strdup("0123456789ABCDEF");
	while ((nbr / 16) != 0)
	{
		res[len - 1] = arr[nbr % 16];
		len--;
		nbr /= 16;
	}
	res[0] = arr[nbr];
	chr = ft_strlen(res);
	ft_putstr(res);
	free(res);
	free(arr);
	return (chr);
}
