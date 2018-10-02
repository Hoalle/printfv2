/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:33:02 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 12:53:20 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_flag_oct_part2(va_list ap, char flag, char *nbr, char c)
{
	unsigned long long int	llnb;
	unsigned long int		lnb;

	lnb = 0;
	llnb = 0;
	if (flag == 'h' || flag == 'z' || flag == 'L')
	{
		llnb = va_arg(ap, unsigned long long int);
		if (flag == 'h')
			llnb = llnb & 0xFFFF;
		nbr = ft_long_long_otoa(llnb);
	}
	else if (c == 'O' || flag == 'l' || flag == 'j')
	{
		lnb = va_arg(ap, unsigned long int);
		nbr = ft_long_otoa(lnb);
	}
	return (nbr);
}

static char		*ft_flag_oct(va_list ap, char *nbr, char flag, char c)
{
	unsigned int nb;

	if ((c == 'o') && flag != 'l' && flag != 'L' && flag != 'h' && flag != 'j'
			&& flag != 'z' && flag != 'H')
	{
		nb = va_arg(ap, unsigned int);
		nbr = ft_otoa(nb);
	}
	else if (flag == 'H' && c != 'O')
	{
		nb = va_arg(ap, unsigned int);
		nbr = ft_char_otoa(nb);
	}
	else if (c == 'O' || flag == 'h' || flag == 'z' || flag == 'L' || flag ==
			'l' || flag == 'j')
		nbr = ft_flag_oct_part2(ap, flag, nbr, c);
	return (nbr);
}

static int		ft_print(char *nbr, int ret)
{
	if (g_hash == '#')
	{
		ft_putchar('0');
		ret++;
	}
	ft_putstr(nbr);
	ret += ft_strlen(nbr);
	return (ret);
}

int				ft_print_octal(va_list ap, char c, char flag)
{
	int		ret;
	char	*nbr;

	nbr = NULL;
	ret = 0;
	if (c == 'o' && flag == 'l')
		c = 'O';
	nbr = ft_flag_oct(ap, nbr, flag, c);
	if (g_p > 0 || g_minfd > 0)
		ret = ft_precision_octal(nbr, ret);
	else
		ret = ft_print(nbr, ret);
	free(nbr);
	return (ret);
}
