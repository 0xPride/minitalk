/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:46:12 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/03 11:43:10 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*u_dst;
	const unsigned char	*u_src;

	if (!dst && !src)
		return (NULL);
	u_dst = (unsigned char *)dst;
	u_src = (const unsigned char *)src;
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len > 0)
		{
			u_dst[len - 1] = u_src[len - 1];
			len--;
		}
	}
	return (dst);
}
