/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:59:16 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/09/03 16:12:52 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	start = 0;
	end = ft_strlen((char *)s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (start <= end && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end >= start && ft_strchr(set, s1[end]))
	{
		end--;
	}
	str = ft_substr((char *)s1, start, end - start + 1);
	return (str);
}
