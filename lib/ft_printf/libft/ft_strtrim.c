/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:39:02 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/10 21:14:59 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_includes(const char *s1, char c)
{
	while (*s1)
	{
		if (*s1 == c)
			return (1);
		s1++;
	}
	return (0);
}

static char	*_ft_strtrim(char const *s1, size_t start, size_t end)
{
	char	*buffer;
	size_t	i;

	buffer = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!buffer)
		return (NULL);
	i = 0;
	while (start < end + 1)
	{
		buffer[i] = s1[start];
		i++;
		start++;
	}
	buffer[i] = '\0';
	return (buffer);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buffer;
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_includes(set, s1[start]))
	{
		start++;
	}
	end = ft_strlen(s1) - 1;
	while (ft_includes(set, s1[end]) && end > 0)
	{
		end--;
	}
	if (!ft_strlen(s1) || end < start)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
		return (buffer);
	}
	return (_ft_strtrim(s1, start, end));
}
