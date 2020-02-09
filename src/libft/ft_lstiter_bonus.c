/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 06:29:13 by mhaddi            #+#    #+#             */
/*   Updated: 2019/11/05 06:35:34 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *tmp;

	if (lst && f)
	{
		tmp = lst;
		while (tmp->next)
		{
			f(tmp->content);
			tmp = tmp->next;
		}
		f(tmp->content);
	}
}
