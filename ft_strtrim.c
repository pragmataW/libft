/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci < yciftci@student.42kocaeli.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:05:24 by yciftci           #+#    #+#             */
/*   Updated: 2022/10/11 17:06:21 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		index;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_check_set(s1[start], set))
		start++;
	while (end > start && ft_check_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (start < end)
		str[index++] = s1[start++];
	str[index] = '\0';
	return (str);
}
