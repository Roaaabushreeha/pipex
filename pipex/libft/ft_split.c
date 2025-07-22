/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:21:56 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/09/02 12:51:51 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lengthc(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && !i)
		{
			i = 1;
			count++;
		}
		else if (*s == c)
		{
			i = 0;
		}
		s++;
	}
	return (count);
}

char	**free_split(char **split)
{
	char	**temp;

	if (split)
	{
		temp = split;
		while (*temp)
		{
			free(*temp);
			temp++;
		}
		free(split);
	}
	return (NULL);
}

static int	lenend(const char *s, char c)
{
	int	length;

	length = 0;
	while (s[length] && s[length] != c)
	{
		length++;
	}
	return (length);
}

static void	init(int *i, int *j, int *start)
{
	*i = 0;
	*start = 0;
	*j = 0;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**str;

	init(&i, &j, &start);
	str = malloc(sizeof(char *) * (lengthc((char *)s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (s[i++] != c)
		{
			start = --i;
			while (s[i] && s[i] != c)
				i++;
			str[j] = ft_substr(s, start, lenend(&s[start], c));
			if (!str[j++])
				return ((free_split(str)));
		}
	}
	str[j] = NULL;
	return (str);
}
// int	main(void)
// {
// 	char **result;
// 	int i = 0;

// 	result = ft_split("roaa abushreeha", 'a');
// 	if (result)
// 	{
// 		while (result[i] != NULL)
// 		{
// 			printf("%s\n", result[i]);
// 			free(result[i]); // Free each substring after printing
// 			i++;
// 		}
// 		free(result); // Free the array of substrings
// 	}

// 	return (0);
// }