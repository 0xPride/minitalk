/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_types2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 23:10:03 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/21 23:10:05 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

char	*char_dup(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	handle_char(t_list **lst, va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	ft_lstadd_back(lst, ft_lstnew(char_dup(c)));
}

void	handle_string(t_list **lst, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (str[0])
		ft_lstadd_back(lst, ft_lstnew(str));
	else
		free(str);
}

void	handle_decimal(t_list **lst, va_list ap)
{
	int		nbr;
	char	*str;

	nbr = va_arg(ap, int);
	str = ft_itoa(nbr);
	ft_lstadd_back(lst, ft_lstnew(str));
}

void	handle_unsigned(t_list **lst, va_list ap)
{
	unsigned int	i;
	char			*str;

	i = va_arg(ap, unsigned int);
	str = ft_ultoa_base((unsigned int)i, DECIMAL);
	ft_lstadd_back(lst, ft_lstnew(str));
}
