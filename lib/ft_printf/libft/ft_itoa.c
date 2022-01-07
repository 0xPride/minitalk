/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:48:09 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/10 17:40:42 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_digits(long n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		digits++;
		n *= -1;
	}
	while (n > 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static void	fill_buffer(char **buffer, long l_n, int digits, int i)
{
	while (digits > i)
	{
		(*buffer)[digits - 1] = l_n % 10 + '0';
		l_n /= 10;
		digits--;
	}
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		digits;
	long	l_n;
	int		i;

	l_n = n;
	i = 0;
	digits = number_digits(l_n);
	buffer = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (n < 0)
	{
		buffer[0] = '-';
		i = 1;
		l_n *= -1;
	}
	else if (n == 0)
	{
		buffer[0] = '0';
	}
	fill_buffer(&buffer, l_n, digits, i);
	return (buffer);
}
