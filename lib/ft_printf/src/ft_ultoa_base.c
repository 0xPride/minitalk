/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:10:08 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/21 22:10:10 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	number_digits(unsigned long long n, size_t b_len)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		digits++;
		n /= b_len;
	}
	return (digits);
}

char	*ft_ultoa_base(unsigned long long nbr, const char *base)
{
	char	*buffer;
	int		digits;
	size_t	b_len;

	b_len = ft_strlen(base);
	digits = number_digits(nbr, b_len);
	buffer = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (nbr == 0)
	{
		buffer[0] = '0';
	}
	digits--;
	while (digits >= 0)
	{
		buffer[digits] = base[nbr % b_len];
		nbr /= b_len;
		digits--;
	}
	return (buffer);
}
