/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:49:05 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/07 17:30:15 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buffer;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	buffer = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buffer[i] = f(i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
