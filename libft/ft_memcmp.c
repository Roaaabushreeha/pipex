/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:58:31 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/29 15:34:39 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

//int memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s1s;
	char	*s2s;

	s1s = (char *)s1;
	s2s = (char *)s2;
	i = 0;
	while (i < n && (s1s || s2s))
	{
		if (s1s[i] != s2s[i])
		{
			return ((unsigned char)s1s[i] - (unsigned char)s2s[i]);
		}
		i++;
	}
	return (0);
}
/*int main()
{
	char *a="roaa";
	char *b="roaa";
	//printf("%d \n",ft_memcmp(a,b,50));
       printf("%d",memcmp(a,b,50));
        }*/
