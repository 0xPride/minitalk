/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habouiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:54:40 by habouiba          #+#    #+#             */
/*   Updated: 2021/11/09 15:55:19 by habouiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_lstclear(t_list *lst, void (*del)(void *))
{
	if (lst->next)
		_ft_lstclear(lst->next, del);
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (*lst)
		_ft_lstclear(*lst, del);
	*lst = NULL;
}
