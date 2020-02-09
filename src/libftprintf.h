/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:00:58 by mhaddi            #+#    #+#             */
/*   Updated: 2020/01/23 17:12:16 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int minusflag_found;
int zeroflag_found;
int precisiondot_found;
int precision_val;
int mfwidth_val;	// about "mfwidth_found": it's not a thing
			// because if mfwidth_val > 0 : it's found
			// but if it was = 0, it's considered as
			// not found since 0 is default anyway:
			// if we justified by 0 nothing will happen
va_list ap;
char specifier;
int counter;

int	ft_printf(const char *s, ...);

#endif
