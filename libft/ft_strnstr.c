/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:42:50 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/29 16:25:18 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char *strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*s;
	char	*l;

	s = (char *)big;
	l = (char *)little;
	if (!ft_strlen(l))
	{
		return (s);
	}
	while (*s && len)
	{
		if (len < ft_strlen(l))
		{
			return (NULL);
		}
		if (ft_strncmp(s, l, ft_strlen(l)) == 0)
		{
			return ((char *)s);
		}
		len--;
		s++;
	}
	return (NULL);
}
/*int main()
{	char c1[] = "Geek for Geak";
	char c2[] = "for";
	printf("%s \n",ft_strnstr(c1, c2 ,9));
        printf("%s" , strnstr(c1 ,c2,9));
}*/
