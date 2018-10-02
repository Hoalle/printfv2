/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:50:53 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 11:53:52 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_flag_hx_part2(va_list ap, char flag, char *nbr, char n)
{
	unsigned long int		lnb;
	unsigned long long int	llnb;

	lnb = 0;
	llnb = 0;
	if (flag == 'l' || flag == 'j')
	{
		lnb = va_arg(ap, unsigned long int);
		nbr = ft_long_htoa(lnb, n);
	}
	if (flag == 'L' || flag == 'z')
	{
		llnb = va_arg(ap, unsigned long long int);
		nbr = ft_long_long_htoa(llnb, n);
	}
	return (nbr);
}

static char		*ft_flag_hx(va_list ap, char *nbr, char flag, char c)
{
	unsigned int		nb;
	int					n;

	if (c == 'x')
		n = 97;
	else
		n = 65;
	if (flag == 'l' || flag == 'j' || flag == 'L' || flag == 'z')
		nbr = ft_flag_hx_part2(ap, flag, nbr, n);
	if (flag == 'H')
	{
		nb = va_arg(ap, unsigned int);
		nbr = ft_char_htoa(nb, n);
	}
	else if (flag != 'H' && flag != 'j' && flag != 'z' && flag != 'l' && flag !=
			'L')
	{
		nb = va_arg(ap, unsigned int);
		nbr = ft_htoa(nb, n);
	}
	return (nbr);
}

static int		ft_print(char *nbr, int ret, char c)
{
	if (g_hash == '#')
	{
		if (c == 'X')
			ft_putstr("0X");
		if (c == 'x')
			ft_putstr("0x");
		ret += 2;
	}
	ft_putstr(nbr);
	ret += ft_strlen(nbr);
	return (ret);
}

int				ft_print_hexa(va_list ap, char c, char flag)
{
	int		ret;
	char	*nbr;
	char	*h;

	if (g_hash == '#')
	{
		if (c == 'X')
			h = ft_strdup("0X");
		else
			h = ft_strdup("0x");
	}
	nbr = NULL;
	ret = 0;
	nbr = ft_flag_hx(ap, nbr, flag, c);
	if (g_p > 0 || g_minfd > 0)
		ret = ft_precision_hexa(nbr, ret, h);
	else
		ret = ft_print(nbr, ret, c);
	free(nbr);
	if (g_hash == '#')
		free(h);
	return (ret);
}
