/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 06:09:39 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/05 06:26:01 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (*lst && del)
	{
		while ((*lst)->next)
		{
			tmp = *lst;
			del((*lst)->content);
			(*lst) = (*lst)->next;
			free(tmp);
		}
		del((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}
