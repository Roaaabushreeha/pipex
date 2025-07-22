/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:36:49 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/31 10:57:27 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;

	str = (char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(str))
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	if (start + len > ft_strlen(str))
		len = ft_strlen(str) - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str + start, len + 1);
	return (ptr);
}
/*int	main(void)
{
	printf("%s", ft_substr("roaa", 2, 2));
}*/