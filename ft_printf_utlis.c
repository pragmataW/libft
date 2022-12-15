/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 02:20:09 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/15 23:28:09 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nbr)
{
	char	*res;
	int		chr;

	res = ft_itoa(nbr);
	chr = ft_strlen(res);
	ft_putstr_fd(res, 1);
	free(res);
	return (chr);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
		ft_putchr(str[i++]);
	return (i);
}

static int	ft_count(unsigned int nbr)
{
	int	count;

	count = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

int	ft_putuint(unsigned int nbr)
{
	char	*res;
	int		chr;

	chr = ft_count(nbr);
	if (nbr == 0)
	{
		ft_putchr('0');
		return (1);
	}
	res = (char *)malloc(sizeof(char) * (chr + 1));
	res[chr] = '\0';
	while (nbr != 0)
	{
		res[--chr] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	ft_putstr(res);
	chr = (ft_strlen(res));
	free(res);
	return (chr);
}
