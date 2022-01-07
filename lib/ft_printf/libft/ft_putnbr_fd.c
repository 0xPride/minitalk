/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:22:49 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/11 15:59:53 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_putnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		_ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	u_n = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u_n *= -1;
	}
	else if (u_n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	_ft_putnbr_fd(u_n, fd);
}
