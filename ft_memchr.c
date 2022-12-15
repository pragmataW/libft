/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci < yciftci@student.42kocaeli.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 07:09:05 by yciftci           #+#    #+#             */
/*   Updated: 2022/10/08 07:25:50 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int c, size_t n)
{
	int				i;
	unsigned char	*s;

	s = (unsigned char *)ptr;
	i = 0;
	while (n > 0)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i++;
		n--;
	}
	return ((void *) NULL);
}
