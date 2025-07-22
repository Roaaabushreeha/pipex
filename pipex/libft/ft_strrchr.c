/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:36:29 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/09/04 11:45:26 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//char	*strrchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*se;

	se = (char *)s;
	i = (ft_strlen(se));
	while (i >= 0)
	{
		if (se[i] == (char)c)
			return (se + i);
		i--;
	}
	if (c == '\0')
		return (se + i);
	return (NULL);
}
// int main ()
//  {
//     char s[]="roaa";
//     printf("%p\n",ft_strrchr(s,'f'));
//     printf("%p",strrchr(s,'f'));
//  }
