/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:02:12 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/31 12:07:49 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*soures;
	char	*dst;
	size_t	i;

	i = n;
	soures = (char *)src;
	dst = (char *)dest;
	if (soures == NULL && dest == NULL)
	{
		return (NULL);
	}
	if (dst < soures || dst >= (soures + n))
	{
		ft_memcpy(dst, soures, n);
	}
	else
	{
		while (i > 0)
		{
			dst[i - 1] = soures[i - 1];
			i--;
		}
	}
	return (dest);
}
/*#include <stdio.h> 
#include <string.h>

int	main(void) 
{ 
    char str[100] = "Learningisfun"; 
    char *first, *second; 
    first = str; 
    second = str; 
    printf("Original string :%s\n ", str); 
      
    // when overlap happens then it just ignore it 
    memcpy(first + 8, first, 10); 
    printf("memcpy overlap : %s\n ", str); 
  
    // when overlap it start from first position 
    ft_memmove(second + 8, first, 10); 
    printf("memmove overlap : %s\n ", str); 
  
    return (0); 
}*/
