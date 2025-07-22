/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:05:08 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/29 12:47:49 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	l;

	n = ft_strlen((char *)src);
	if (size == 0)
	{
		return (n);
	}
	if (n >= size)
	{
		l = size - 1;
	}
	else
		l = n;
	ft_memcpy(dst, src, l);
	dst[l] = '\0';
	return (n);
}
/*int main ()
{
char s[]="roaa";
char	d[5];


//printf("%ld",ft_strlcpy(d,s,2));
printf("%ld",strlcpy(d,s,2));


}*/
