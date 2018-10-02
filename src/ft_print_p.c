/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 11:35:37 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 13:59:49 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_print_p(va_list ap)
{
	int					ret;
	char				*nbr;
	unsigned long int	c;

	ret = 0;
	c = va_arg(ap, unsigned long);
	nbr = ft_long_htoa(c, 97);
	if (g_p > 0 || g_minfd > 0)
	{
		g_hash = '#';
		ret = ft_precision_hexa(nbr, ret, "0x");
	}
	else
	{
		ft_putstr("0x");
		ft_putstr(nbr);
		ret = 2 + ft_strlen(nbr);
	}
	free(nbr);
	return (ret);
}
