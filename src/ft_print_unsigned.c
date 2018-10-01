/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:42:27 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:21:30 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_flag_usg_part2(va_list ap, char *nbr, char flag, char c)
{
	unsigned long long int	llnb;
	unsigned short int		snb;
	unsigned int			nb;

	if ((flag == 'L' || flag == 'z') && c != 'U')
	{
		llnb = va_arg(ap, unsigned long long int);
		nbr = ft_long_long_utoa(llnb);
	}
	if (((flag == 'h') && c != 'U') || (c == 'U' && flag == 'H'))
	{
		snb = va_arg(ap, int);
		nbr = ft_short_utoa(snb);
	}
	if (flag == 'H' && c != 'U')
	{
		nb = va_arg(ap, unsigned int);
		nbr = ft_char_utoa(nb);
	}
	return (nbr);
}

static char		*ft_flag_usg(va_list ap, char *nbr, char flag, char c)
{
	unsigned int		nb;
	unsigned long int	lnb;

	if (c == 'u' && flag != 'H' && flag != 'h' && flag != 'l' && flag != 'L' &&
			flag != 'j' && flag != 'z')
	{
		nb = va_arg(ap, unsigned int);
		nbr = ft_utoa(nb);
	}
	if ((c == 'U' || flag == 'l' || flag == 'j' || (c == 'U' && flag == 'h')) &&
			flag != 'H')
	{
		lnb = va_arg(ap, unsigned long int);
		nbr = ft_long_utoa(lnb);
	}
	else
		nbr = ft_flag_usg_part2(ap, nbr, flag, c);
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

int				ft_print_unsigned(va_list ap, char c, char flag)
{
	int		ret;
	char	*nbr;

	nbr = NULL;
	ret = 0;
	if (c == 'u' && flag == 'l')
		c = 'U';
	nbr = ft_flag_usg(ap, nbr, flag, c);
	if (g_p > 0 || g_minfd > 0)
		ret = ft_precision_unsigned(nbr, ret);
	else
		ret = ft_print(nbr, ret);
	free(nbr);
	return (ret);
}
