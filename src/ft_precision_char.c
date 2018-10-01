/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:00:58 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:13:58 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_precision_char_part1_1(int ret, char c)
{
	int tmp;

	if (g_prec == '.' && g_p > 0)
	{
		tmp = g_p - 1;
		while (tmp--)
		{
			ft_putchar('0');
			ret++;
		}
	}
	else if (g_minfd > 0)
	{
		tmp = g_minfd - 1;
		while (tmp--)
		{
			ft_putchar('0');
			ret++;
		}
	}
	ft_putchar(c);
	return (ret);
}

static int	ft_precision_char_part1_2(int ret, char c)
{
	int tmp;

	if (g_prec == '.' && g_p > 0)
	{
		tmp = g_p - 1;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	else if (g_minfd > 0)
	{
		tmp = g_minfd - 1;
		while (tmp--)
		{
			ft_putchar(' ');
			ret++;
		}
	}
	ft_putchar(c);
	return (ret);
}

static int	ft_precision_char_part2(int ret, char c)
{
	int tmp;

	tmp = 0;
	ft_putchar(c);
	if (g_prec == '.')
	{
		if (g_p >= 1)
			tmp = g_p - 1;
	}
	else
	{
		if (g_minfd >= 1)
			tmp = g_minfd - 1;
	}
	ret = tmp + 1;
	while (tmp--)
		ft_putchar(' ');
	return (ret);
}

int			ft_precision_char(int ret, char c)
{
	if (g_noprec != '-')
	{
		if (g_zero == '0')
			ret = ft_precision_char_part1_1(ret, c);
		else
			ret = ft_precision_char_part1_2(ret, c);
	}
	else
		ret = ft_precision_char_part2(ret, c);
	return (ret);
}
