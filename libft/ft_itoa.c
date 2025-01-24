/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 08:15:49 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/09/02 13:19:49 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*static void	reverse(char *str, int len)
{
	int		start;
	int		end;
	char	temp;

	end = len - 1;
	start = 0;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}
*/
// static int	len(int n)
// {
// 	int	j;

// 	j = 0;
// 	if (n < 0)
// 	{
// 		n = -n;
// 	}
// 	while (n != 0)
// 	{
// 		n = (n / 10);
// 		j++;
// 	}
// 	return (j);
// }

// char	*ft_itoa(int n)
// {
// 	char	*res;
//         int             leng;
//         int     sign;

//         sign = 1;
// 	if (n == -2147483648)
// 		return (ft_strdup("-2147483648"));

// 	leng = len(n);
// 	if (n < 0)
// 	{
// 		sign = -1;
//                 n = -n;
// 		leng++;
// 	}
// 	res = (char *)malloc((leng + 1) * sizeof(char));
// 	res[leng] = '\0';
// 	while (leng)
// 	{
// 		res[--leng] = n % 10 + '0';
// 		n /= 10;
// 	}
//         if (sign == -1)
// 		res[0] = '-';
// 	return (res);
// }

/*static size_t lenstr(int n){

size_t			i;
i=0;
        while(n!=0)
        {
                n=n/10;
                i++;
        }
        return(i);
}
char	*ft_itoa(int n)
{
        int len;
        char *str;
        size_t i;
        int sign;

        i=0;
        sign=0;
       if(n==INT_MIN)
                return(ft_strdup("-2147483648"));
       len=lenstr(n)-1;
     
        if(n<0)
       {
                sign=-1; 
                n*=-1;
       }
        else 
        sign=0;
       str=malloc(sizeof(char)*(len -= sign ));
    
       while (len >= 0)
       {
          
                str[len--]=(n % 10) + '0';
                (n /= 10);
                i++;
                  
       }
       if(sign == -1)
                str[0] = '-';
       
      
        return(str);
}



 int    main(void)
 {
     printf("%s", ft_itoa(654654));
 }*/
static size_t	lenst(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while ((n != 0))
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*init(int *min, int *len, int n, int *sign)
{
	*min = 0;
	*len = lenst(n);
	*sign = 0;
	return (ft_calloc((*len + 1), sizeof(char)));
}

char	*ft_itoa(int n)
{
	int		sign;
	char	*final;
	int		i;
	int		min;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	final = init(&min, &i, n, &sign);
	if (!final)
		return (NULL);
	final[0] = '0';
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (i > 0)
	{
		final[i - 1] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	if (sign == -1)
		final[i] = '-';
	return (final);
}

// int    main(void)
// {
//      printf("%s", ft_itoa(-+654654));
// }