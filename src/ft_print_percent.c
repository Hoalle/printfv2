/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:04:29 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 13:06:54 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void		ft_print_perc_s(int tmp, char g)
{
	if (g_zero == '0' && g_p != 0 && g_prec == '.')
	{
		tmp = g_p-- - 1;
		while (g_p--)
			ft_putchar(g);
	}
	if (g_noprec != '-' && g_prec != '.')
	{
		while (g_minfd-- >= 0)
			ft_putchar(g);
	}
}

int				ft_print_percent(char c)
{
	int		tmp;
	char	g;

	if (g_zero == '0' && g_noprec != '-')
		g = '0';
	else
		g = ' ';
	tmp = 0;
	if (g_minfd >= 1 && g_prec != '.')
		tmp = g_minfd - 1;
	if (g_prec == '.' && g_minfd < 1 && g_p >= 1)
		tmp = g_p - 1;
	g_minfd -= 2;
	ft_print_perc_s(tmp, g);
	ft_putchar(c);
	if (g_noprec == '-' && g_prec != '.')
	{
		while (g_minfd-- >= 0)
			ft_putchar(g);
	}
	return (tmp + 1);
}
