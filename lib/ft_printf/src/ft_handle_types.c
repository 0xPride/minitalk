/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 22:46:52 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/21 22:46:53 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	handle_hex(t_list **lst, va_list ap, char c)
{
	unsigned int	num;
	char			*str;

	num = va_arg(ap, unsigned int);
	if (c == 'x')
		str = ft_ultoa_base((unsigned int)num, L_HEX);
	else
		str = ft_ultoa_base((unsigned int)num, U_HEX);
	ft_lstadd_back(lst, ft_lstnew(str));
}

void	handle_ptr(t_list **lst, va_list ap)
{
	unsigned long	num;
	char			*str;
	char			*tmp;

	num = va_arg(ap, unsigned long);
	tmp = ft_ultoa_base(num, L_HEX);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	ft_lstadd_back(lst, ft_lstnew(str));
}

void	handle_percenct(t_list **lst)
{
	char	*str;

	str = char_dup('%');
	ft_lstadd_back(lst, ft_lstnew(str));
}

void	handle_types(t_list **lst, va_list ap, const char *str, size_t i)
{
	if (str[i] == 'c')
		handle_char(lst, ap);
	else if (str[i] == 's')
		handle_string(lst, ap);
	else if (str[i] == 'd' || str[i] == 'i')
		handle_decimal(lst, ap);
	else if (str[i] == 'u')
		handle_unsigned(lst, ap);
	else if (str[i] == 'x' || str[i] == 'X')
		handle_hex(lst, ap, str[i]);
	else if (str[i] == 'p')
		handle_ptr(lst, ap);
	else if (str[i] == '%')
		handle_percenct(lst);
}
