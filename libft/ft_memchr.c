/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:51:40 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/29 14:24:02 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void    *memchr(const void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*se;
	size_t	i;

	se = (char *)s;
	i = 0;
	while (i < n)
	{
		if (se[i] == (char)c)
		{
			return ((void *)(se + i));
		}
		i++;
	}
	return (NULL);
}
/*int main()
{
        
        printf("%p\n",ft_memchr("roaa",'a',3));
      printf("%p\n",memchr("roaa",'a',3));

}*/
