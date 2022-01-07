/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:16:43 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/07 17:00:09 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*char_s;

	char_s = (unsigned char *)s;
	if (!n)
		return ;
	while (n > 0)
	{
		*char_s = 0;
		char_s++;
		n--;
	}
}
