/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_octal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:05:08 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:24:52 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_precision_o_part1_1(int ret, char *nbr, int len, int hash)
{
	int		tmp;

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
	if (g_hash == '#')
		ft_putchar('0');
	if (g_minfd > len)
	{
		tmp = g_minfd - len - hash;
		while (tmp--)
		{
			ft_putchar('0');
			ret++;
		}
	}
	ft_putstr(nbr);
	return (ret + len + hash);
}

static int		ft_precision_o_part1_2(int ret, char *nbr, int len, char g)
{
	int tmp;

	if (g_hash == '#' && g_zero == '0')
		ft_putchar('0');
	if (g_minfd > len)
	{
		tmp = g_minfd - len;
		while (tmp--)
		{
			ft_putchar(g);
			ret++;
		}
	}
	if (g_hash == '#' && g_zero != '0')
		ft_putchar('0');
	ft_putstr(nbr);
	return (ret + len);
}

static int		ft_precision_o_part2_1(int ret, char *nbr, int len, int hash)
{
	int tmp;

	if (g_hash == '#')
		ft_putchar('0');
	if (g_minfd > len)
	{
		tmp = g_minfd - len - hash;
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
	return (ret + len + hash);
}

static int		ft_precision_o_part2_2(int ret, char *nbr, int len)
{
	int tmp;

	tmp = 0;
	if (g_hash == '#')
		ft_putchar('0');
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

int				ft_precision_octal(char *nbr, int ret)
{
	int		len;
	char	g;
	int		hash;

	len = ft_strlen(nbr);
	g = ' ';
	hash = 0;
	if (g_zero == '0')
		g = '0';
	if (g_prec != '.' && g_hash == '#')
		len++;
	else if (g_prec == '.' && g_hash == '#')
		hash = 1;
	if (g_noprec != '-')
	{
		if (g_prec == '.')
			ret = ft_precision_o_part1_1(ret, nbr, len, hash);
		else
			ret = ft_precision_o_part1_2(ret, nbr, len, g);
	}
	else
	{
		if (g_prec == '.')
			ret = ft_precision_o_part2_1(ret, nbr, len, hash);
		else
			ret = ft_precision_o_part2_2(ret, nbr, len);
	}
	return (ret);
}
