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

void router_lvl1(char **str, void *arg)
{
	if (**str == '%')
	{
		write(1, *str,1);
		counter++;
	}
	else if (IS_FLAG(**str))
		get_flag();
	else if(IS_WIDTH(**str))
		get_width();
	else if (IS_PRECISION(**str))
		get_precision();
	else if (IS_LENGTH(**str))
		get_length();
	else if (IS_SPECIFIER(**str))
		get_specifier();
}

void router_lvl2(char **str, void *arg)
{
	if (IS_WIDTH(**str))
		get_width();
	else if (IS_PRECISION(**str))
		get_precision();
	else if (IS_LENGTH(**str))
		get_length();
	else if (IS_SPECIFIER(**str))
		get_specifier();
}

void router_lvl3(char **str, void *arg)
{
	if (IS_PRECISION(**str))
		get_precision();
	else if (IS_LENGTH(**str))
		get_length();
	else if (IS_SPECIFIER(**str))
		get_specifier();
}

void router_lvl4(char **str, void *arg)
{
	if (IS_LENGTH(**str))
		get_length();
	else if (IS_SPECIFIER(**str))
		get_specifier();
}
void router_lvl5(char **str, void *arg)
{
	if (IS_LENGTH(**str))
		get_length();
	else if (IS_SPECIFIER(**str))
		get_specifier();
}
