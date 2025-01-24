/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:57:47 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/29 15:51:22 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*s;
	char	*btee5a;

	i = 0;
	s = (char *)dest;
	btee5a = (char *)src;
	if (!s && !btee5a)
	{
		return (NULL);
	}
	while (n)
	{
		s[i] = btee5a[i];
		n--;
		i++;
	}
	return (dest);
}
/*int main()
{
	char s[10]="roaa";
	char c[10];
	printf("%s\n",(char *)memcpy(c,s,1));
	printf("%s\n",(char *)ft_memcpy(c,s,1));
}*/
