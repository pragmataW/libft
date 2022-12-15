/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42.tr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:23:16 by yciftci           #+#    #+#             */
/*   Updated: 2022/10/04 17:19:32 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		((unsigned char *)dest)[i] = c;
		i++;
		len--;
	}
	return (dest);
}
//fonksiyonu kullanırken eğer ft_memset("ddfwf", 'a', 5) şeklinde
//kullanırsak gönderdiğimiz string bellekte
//char *ddfwf = ddfwf şeklinde tanımlandığından bellekte
//değiştirilemez bir yere tanımlanıyor bu yüzden bus error
//yiyoruz. Bunun olmaması için göndereceğimiz parametreyi 
//öncelike char dest[] = "ddfwf" şeklinde tanımlayıp 
//sonra parametre olarak dest dizisini göndermeliyiz.
