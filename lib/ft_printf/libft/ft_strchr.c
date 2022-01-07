/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:37:21 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/07 17:01:08 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_chr;

	i = 0;
	c_chr = (char)c;
	while (s[i])
	{
		if (s[i] == c_chr)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c_chr)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
