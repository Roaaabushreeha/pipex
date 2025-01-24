/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabu-shr <rabu-shr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:46:41 by rabu-shr          #+#    #+#             */
/*   Updated: 2024/08/31 20:01:21 by rabu-shr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	num2;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	if (num / 10 != '\0')
	{
		ft_putnbr_fd(num / 10, fd);
	}
	num2 = (num % 10 + '0');
	write(fd, &num2, 1);
}
/*int     main()
{
        ft_putnbr(2147483648);
}*/