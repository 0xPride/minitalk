/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:23:59 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/07 16:57:33 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			{
				if (ft_strlen(needle) > len - i)
				{
					return (NULL);
				}
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
