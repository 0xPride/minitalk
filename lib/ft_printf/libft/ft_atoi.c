/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:04:24 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/11 15:59:43 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	fill_buffer(long num, const char *str, int sign, int i)
{
	while (ft_isdigit(str[i]))
	{
		if ((num * 10 + (str[i]) - '0') / 10 != num)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(num * sign));
}

int	ft_atoi(const char *str)
{
	long			num;
	size_t			i;
	int				sign;

	num = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign *= '+' - str[i] + 1;
		i++;
	}
	return (fill_buffer(num, str, sign, i));
}
