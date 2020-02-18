/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hach <ael-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:33:42 by ael-hach          #+#    #+#             */
/*   Updated: 2020/02/17 16:02:32 by ael-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void router(char **str, void *arg)
{
	*str++;
	if (**str == '%')
	{
		write(1, *str,1);
		counter++;
	}
	else if (IS_FLAG(**str))
		get_flag();
	else if(IS_WIDTH())
		get_width();
	else if (IS_PRECISION())
		get_precision();
	else if (IS_LENGTH())
		get_length();
	else if (IS_SPECIFIER(**str))
		get_specifier();
}
