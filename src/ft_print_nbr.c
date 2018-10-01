/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 16:10:01 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:20:54 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_flag_nbr_part2(va_list ap, char flag, char *nbr, char c)
{
	long int	lnb;
	int			nb;

	if (c == 'd' && flag != 'h' && flag != 'l' && flag != 'L' && flag != 'z'
			&& flag != 'j' && flag != 'H')
	{
		nb = va_arg(ap, int);
		nbr = ft_itoa(nb);
	}
	if ((c == 'D' || flag == 'l' || flag == 'j' || flag == 'z' || (c == 'D' &&
					flag == 'H')) && flag != 'L')
	{
		lnb = va_arg(ap, long int);
		nbr = ft_long_itoa(lnb);
	}
	if (flag == 'H' && flag != 'l' && c != 'D')
	{
		nb = va_arg(ap, int);
		nbr = ft_char_itoa(nb);
	}
	return (nbr);
}

static char		*ft_flag_nbr(va_list ap, char *nbr, char flag, char c)
{
	long long int	llnb;
	short int		snb;

	if (flag != 'L' && flag != 'h')
		nbr = ft_flag_nbr_part2(ap, flag, nbr, c);
	if (flag == 'L')
	{
		llnb = va_arg(ap, long long int);
		nbr = ft_long_long_itoa(llnb);
	}
	if (flag == 'h')
	{
		snb = va_arg(ap, int);
		nbr = ft_short_itoa(snb, c);
	}
	return (nbr);
}

static int		ft_print(char *nbr, int ret)
{
	if (nbr[0] != '-')
	{
		if (g_space == ' ' && g_plus != '+')
		{
			ft_putchar(' ');
			ret++;
		}
		else if (g_plus == '+')
		{
			ft_putchar('+');
			ret++;
		}
	}
	ft_putstr(nbr);
	ret += ft_strlen(nbr);
	return (ret);
}

int				ft_print_nbr(va_list ap, char c, char flag)
{
	int		ret;
	char	*nbr;

	nbr = NULL;
	ret = 0;
	if (c == 'd' && flag == 'l')
		c = 'D';
	if (c == 'i')
		c = 'd';
	nbr = ft_flag_nbr(ap, nbr, flag, c);
	if (g_p > 0 || g_minfd > 0)
		ret = ft_precision_nbr(nbr, ret);
	else
		ret = ft_print(nbr, ret);
	free(nbr);
	return (ret);
}
