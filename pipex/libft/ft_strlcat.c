/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:49:00 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/29 09:02:24 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t	strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	dst_s;
	size_t	src_s;

	i = 0;
	j = 0;
	dst_s = ft_strlen((char *)dest);
	src_s = ft_strlen((char *)src);
	a = size - dst_s - 1;
	if (size <= dst_s)
		return (src_s + size);
	while (dest[i])
		i++;
	while (src[j] && j < a)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dst_s + src_s);
}
/*int main ()
{
char s[]="talal";
char d[]="ahmad";
printf("%ld",strlcat(d, s, 3));
//printf("%ld",ft_strlcat(d,s,2));
//printf("%s", d);
}*/
