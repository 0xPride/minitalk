/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:51:34 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/07 16:58:02 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occurence;
	char	c_chr;

	i = 0;
	last_occurence = NULL;
	c_chr = (char)c;
	while (s[i])
	{
		if (s[i] == c_chr)
		{
			last_occurence = (char *)&s[i];
		}
		i++;
	}
	if (s[i] == c_chr)
		last_occurence = (char *)&s[i];
	return (last_occurence);
}
