/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 11:10:42 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/09/01 11:52:57 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 && !s2)
		return (NULL);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		ptr[i++] = s2[j++];
	}
	ptr[len] = '\0';
	return (ptr);
}
/*int main(){
        printf("%s",ft_strjoin("\0","\0"));
}*/