/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:22:38 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:22:00 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_precision_nbr_part1_1(int ret, char *nbr, int len, int sign)
{
	int tmp;

	tmp = 0;
	if (g_p > g_minfd)
	{
		if (g_minfd > len)
			tmp = g_p - g_minfd - sign;
		else
			tmp = g_p - len - sign;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	if (g_plus == '+' && nbr[0] != '-')
		ft_putchar('+');
	else if (g_space == ' ' && nbr[0] != '-')
		ft_putchar(' ');
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
	return (ret + len + sign);
}

static int		ft_precision_nbr_part1_2(int ret, char *nbr, int len, char g)
{
	int tmp;

	if (g_zero == '0')
	{
		if (g_space == ' ' && g_plus != '+' && nbr[0] != '-')
			ft_putchar(' ');
		else if (g_plus == '+' && nbr[0] != '-')
			ft_putchar('+');
	}
	if (g_minfd > len)
	{
		tmp = g_minfd - len;
		while (tmp--)
		{
			ft_putchar(g);
			ret++;
		}
	}
	if (g_space == ' ' && g_plus != '+' && nbr[0] != '-' && g_zero != '0')
		ft_putchar(' ');
	else if (g_plus == '+' && nbr[0] != '-' && g_zero != '0')
		ft_putchar('+');
	ft_putstr(nbr);
	return (ret + len);
}

static int		ft_precision_nbr_part2_1(int ret, char *nbr, int len, int sign)
{
	int tmp;

	tmp = 0;
	if (g_plus == '+' && nbr[0] != '-')
		ft_putchar('+');
	else if (g_space == ' ' && nbr[0] != '-')
		ft_putchar(' ');
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
			tmp = g_p - g_minfd - sign;
		else
			tmp = g_p - len - sign;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	return (ret + len + sign);
}

static int		ft_precision_nbr_part2_2(int ret, char *nbr, int len)
{
	int tmp;

	tmp = 0;
	if (g_space == ' ' && g_plus != '+' && nbr[0] != '-')
		ft_putchar(' ');
	else if (g_plus == '+' && nbr[0] != '-')
		ft_putchar('+');
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

int				ft_precision_nbr(char *nbr, int ret)
{
	int		len;
	char	g;
	int		sign;

	len = ft_strlen(nbr);
	g = ' ';
	sign = 0;
	if (g_zero == '0')
		g = '0';
	if (nbr[0] != '-' && (g_plus == '+' || g_space == ' ') && g_prec != '.')
		len++;
	else if (nbr[0] != '-' && (g_plus == '+' || g_space == ' ') && g_prec ==
			'.')
		sign = 1;
	if (g_noprec != '-')
	{
		if (g_prec == '.')
			ret = ft_precision_nbr_part1_1(ret, nbr, len, sign);
		else
			ret = ft_precision_nbr_part1_2(ret, nbr, len, g);
	}
	else
	{
		if (g_prec == '.')
			ret = ft_precision_nbr_part2_1(ret, nbr, len, sign);
		else
			ret = ft_precision_nbr_part2_2(ret, nbr, len);
	}
	return (ret);
}
