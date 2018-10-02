/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 12:07:34 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 12:41:22 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_precision_str_part1_1(int ret, char *str, int len, char g)
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
	ft_putstr(str);
	return (ret + len);
}

static int	ft_precision_str_part1_2(int ret, char *str, int len, char g)
{
	int tmp;
	int tmplen;
	int i;

	i = 0;
	tmplen = len;
	if (g_minfd < len)
		tmplen = g_minfd;
	if (g_p > tmplen)
	{
		tmp = g_p - tmplen;
		while (tmp--)
		{
			ft_putchar(g);
			ret++;
		}
	}
	ret = ret + tmplen;
	if (tmplen < len)
		while (tmplen--)
			ft_putchar(str[i++]);
	else
		ft_putstr(str);
	return (ret);
}

static int	ft_precision_str_part2_1(int ret, char *str, int len)
{
	int tmp;

	ft_putstr(str);
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

static int	ft_precision_str_part2_2(int ret, char *str, int len)
{
	int tmp;
	int tmplen;
	int i;

	i = 0;
	tmplen = len;
	if (g_minfd < len)
		tmplen = g_minfd;
	len = tmplen;
	if (len < (int)ft_strlen(str))
		while (tmplen--)
			ft_putchar(str[i++]);
	else
		ft_putstr(str);
	if (g_p > len)
	{
		tmp = g_p - len;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	return (ret + len);
}

int			ft_precision_str(int ret, char *str)
{
	int		len;
	char	g;

	len = ft_strlen(str);
	g = ' ';
	if (g_zero == '0')
		g = '0';
	if (g_noprec != '-')
	{
		if (g_prec != '.')
			ret = ft_precision_str_part1_1(ret, str, len, g);
		else
			ret = ft_precision_str_part1_2(ret, str, len, g);
	}
	else
	{
		if (g_prec != '.')
			ret = ft_precision_str_part2_1(ret, str, len);
		else
			ret = ft_precision_str_part2_2(ret, str, len);
	}
	return (ret);
}
