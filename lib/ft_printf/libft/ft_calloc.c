/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:19:39 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/03 18:19:40 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*buffer;
	size_t	b_size;

	b_size = count * size;
	buffer = (char *)malloc(b_size);
	if (!buffer)
		return (NULL);
	ft_memset(buffer, '\0', b_size);
	return ((void *)buffer);
}
