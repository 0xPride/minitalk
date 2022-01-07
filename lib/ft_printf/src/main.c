/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:57:05 by habouiba          #+#    #+#             */
/*   Updated: 2021/12/18 12:04:11 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

char	*ft_substr_wrapper(const char *s, size_t i)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[i + len] && s[i + len] != '%')
		len++;
	word = ft_substr(s, i, len);
	return (word);
}

static void	lst_content_len(t_list *lst, int **len)
{
	int	tmp;

	tmp = 0;
	while (lst)
	{
		tmp = ft_strlen(lst->content);
		if (!tmp)
			**len = **len + 1;
		else
			**len = **len + tmp;
		lst = lst->next;
	}
}

static char	*ft_lst_to_str(t_list *lst, int *len)
{
	char	*buffer;
	t_list	*tmp;
	size_t	w_len;
	int		tmp_len;

	buffer = NULL;
	*len = 0;
	tmp = lst;
	lst_content_len(lst, &len);
	buffer = (char *)ft_calloc(*len + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	tmp_len = 0;
	while (lst)
	{
		w_len = ft_strlen(lst->content);
		if (!w_len)
			w_len++;
		ft_memmove(&buffer[tmp_len], lst->content, w_len);
		tmp_len += w_len;
		lst = lst->next;
	}
	return (buffer);
}

static int	write_buffer(t_list *lst)
{
	char	*buffer;
	int		len;

	len = 0;
	buffer = ft_lst_to_str(lst, &len);
	ft_lstclear(&lst, free);
	write(1, buffer, len);
	free(buffer);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	t_list	*list;
	va_list	ap;

	list = NULL;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			handle_types(&list, ap, str, i);
			i++;
		}
		else
		{
			ft_lstadd_back(&list, ft_lstnew(ft_substr_wrapper(str, i)));
			while (str[i] && str[i] != '%')
				i++;
		}
	}
	return (write_buffer(list));
}
