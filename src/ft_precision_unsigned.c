/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:02:38 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:22:57 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_precision_u_part1_1(int ret, char *nbr, int len)
{
	int tmp;

	if (g_p > g_minfd)
	{
		if (g_minfd > len)
			tmp = g_p - g_minfd;
		else
			tmp = g_p - len;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	if (g_minfd > len)
	{
		tmp = g_minfd - len;
		while (tmp--)
		{
			ft_putchar('0');
			ret++;
		}
	}
	ft_putstr(nbr);
	return (ret + len);
}

static int		ft_precision_u_part1_2(int ret, char *nbr, int len, char g)
{
	int tmp;

	if (g_minfd > len)
	{
		tmp = g_minfd - len;
		while (tmp--)
		{
			ft_putchar(g);
			ret++;
		}
	}
	ft_putstr(nbr);
	return (ret + len);
}

static int		ft_precision_u_part2_1(int ret, char *nbr, int len)
{
	int tmp;

	if (g_minfd > len)
	{
		tmp = g_minfd - len;
		while (tmp--)
		{
			ft_putchar('0');
			ret++;
		}
	}
	ft_putstr(nbr);
	if (g_p > g_minfd)
	{
		if (g_minfd > len)
			tmp = g_p - g_minfd;
		else
			tmp = g_p - len;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	return (ret + len);
}

static int		ft_precision_u_part2_2(int ret, char *nbr, int len)
{
	int tmp;

	tmp = 0;
	ft_putstr(nbr);
	if (g_minfd > len)
	{
		tmp = g_minfd - len;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	return (ret + len);
}

int				ft_precision_unsigned(char *nbr, int ret)
{
	int		len;
	char	g;

	len = ft_strlen(nbr);
	g = ' ';
	if (g_zero == '0')
		g = '0';
	if (g_noprec != '-')
	{
		if (g_prec == '.')
			ret = ft_precision_u_part1_1(ret, nbr, len);
		else
			ret = ft_precision_u_part1_2(ret, nbr, len, g);
	}
	else
	{
		if (g_prec == '.')
			ret = ft_precision_u_part2_1(ret, nbr, len);
		else
			ret = ft_precision_u_part2_2(ret, nbr, len);
	}
	return (ret);
}
