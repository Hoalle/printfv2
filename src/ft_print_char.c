/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:34:17 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 16:04:40 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_print_char(va_list ap, char c)
{
	int ret;

	ret = 1;
	if (c == 'c')
		c = va_arg(ap, int);
	else
		c = va_arg(ap, wint_t);
	if (g_p > 0 || g_minfd > 0)
		ft_precision_char(ret, c);
	else
		ft_putchar(c);
	return (ret);
}
