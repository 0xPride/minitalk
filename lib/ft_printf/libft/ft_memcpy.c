/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:30:14 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/02 14:08:57 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*c_dst;
	char	*c_src;

	if (!dst && !src)
	{
		return (NULL);
	}
	c_dst = (char *)dst;
	c_src = (char *)src;
	while (n > 0)
	{
		*c_dst = *c_src;
		n--;
		c_src++;
		c_dst++;
	}
	return (dst);
}
