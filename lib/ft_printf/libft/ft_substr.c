/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:03:46 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/11 15:59:11 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buffer;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
		return (buffer);
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		buffer[i] = s[i + start];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
