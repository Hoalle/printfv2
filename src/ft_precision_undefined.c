/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_undefined.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:04:08 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 16:00:16 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static void			ft_no_prec(char *nbr, int nbflags, int c)
{
	int len;

	len = ft_strlen(nbr);
	if (g_noprec == '-' && g_minfd >= len && g_p == 0)
		c = c + g_minfd - ft_strlen(nbr);
	else if (g_noprec == '-' && g_minfd >= len && g_p >= g_minfd)
		c = c + g_p - g_minfd;
	else if (g_noprec == '-' && g_p >= len && g_minfd < len)
		c = c + g_p - len;
	if (nbflags != 0)
		c--;
	if (g_noprec == '-')
	{
		while (c--)
			ft_putchar(' ');
	}
}

static int		ft_precision_undefined_suite(char *f, int tmp, char g)
{
	int count;

	count = g_p - 1;
	if (g_noprec != '-')
	{
		g_p--;
		while (g_p--)
			ft_putchar(g);
	}
	else if (g_noprec == '-')
	{
		ft_putchar(f[tmp]);
		tmp++;
		count++;
		ft_no_prec("0", 0, 0);
	}
	return (count);
}

int			ft_precision_undefined(int tmp, int count, char *f)
{
	char g;

	g = ' ';
	if (g_zero == '0')
		g = '0';
	if (g_prec != '.')
	{
		count = g_minfd - 1;
		if (g_noprec != '-')
		{
			g_minfd--;
			while (g_minfd--)
				ft_putchar(g);
		}
		else if (g_noprec == '-')
		{
			ft_putchar(f[tmp++]);
			count++;
			ft_no_prec("0", 0, 0);
		}
	}
	if (g_prec == '.')
		count = ft_precision_undefined_suite(f, tmp, g);
	return (count);
}
