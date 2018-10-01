/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:14:21 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:25:57 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_precision_h_part1_1(char *h, char *nbr, int len, int hash)
{
	int tmp;
	int ret;

	ret = 0;
	if (g_p > g_minfd)
	{
		if (g_minfd > len)
			tmp = g_p - g_minfd;
		else
			tmp = g_p - len - hash;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	if (g_hash == '#')
		ft_putstr(h);
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
	return (ret + len + hash);
}

static int		ft_precision_h_part1_2(char *h, char *nbr, int len, char g)
{
	int		tmp;
	int		ret;

	ret = 0;
	if (g_hash == '#' && g_zero == '0')
		ft_putstr(h);
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
		ft_putstr(h);
	ft_putstr(nbr);
	return (ret + len);
}

static int		ft_precision_h_part2_1(char *h, char *nbr, int len, int hash)
{
	int tmp;
	int ret;

	ret = 0;
	if (g_hash == '#')
		ft_putstr(h);
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
			tmp = g_p - len - hash;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	return (ret + len + hash);
}

static int		ft_precision_h_part2_2(char *h, char *nbr, int len)
{
	int tmp;
	int ret;

	ret = 0;
	if (g_hash == '#')
		ft_putstr(h);
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

int				ft_precision_hexa(char *nbr, int ret, char *h)
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
		len += 2;
	else if (g_prec == '.' && g_hash == '#')
		hash = 2;
	if (g_noprec != '-')
	{
		if (g_prec == '.')
			ret = ft_precision_h_part1_1(h, nbr, len, hash);
		else
			ret = ft_precision_h_part1_2(h, nbr, len, g);
	}
	else
	{
		if (g_prec == '.')
			ret = ft_precision_h_part2_1(h, nbr, len, hash);
		else
			ret = ft_precision_h_part2_2(h, nbr, len);
	}
	return (ret);
}
