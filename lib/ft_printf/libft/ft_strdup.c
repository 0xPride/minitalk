/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:39:50 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/03 18:39:51 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	size_t	i;

	buffer = (char *)malloc(ft_strlen(s1) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = '\0';
	return ((void *)buffer);
}
