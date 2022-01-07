/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:18:13 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/11 16:00:04 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean_buffer(char **lst)
{
	size_t	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

static char	*ft_strndup(char **list, const char *s1, size_t start, size_t n)
{
	char	*buffer;
	size_t	i;

	buffer = (char *)malloc(n + 1);
	if (!buffer)
	{
		clean_buffer(list);
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		buffer[i] = s1[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**fill_buffer(const char *s, char **list, char c, size_t i)
{
	size_t	j;
	size_t	len;

	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			list[j] = ft_strndup(list, s, i, len);
			if (!list[j])
				return (NULL);
			list[j + 1] = NULL;
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**list;

	if (!s)
		return (NULL);
	list = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!list)
		return (NULL);
	*list = NULL;
	return (fill_buffer(s, list, c, 0));
}
