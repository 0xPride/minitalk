/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:28:50 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/12 09:46:30 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buffer;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	buffer = ft_calloc(size + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	ft_strlcat(buffer, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(buffer, (char *)s2, size + 1);
	return (buffer);
}
