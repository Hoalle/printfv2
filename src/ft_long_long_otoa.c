/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_long_otoa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:52:29 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 15:55:02 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	char	*ft_s_llotoa(void)
{
	char *str;

	str = ft_strdup("1777777777777777777777");
	return (str);
}

char			*ft_long_long_otoa(unsigned long long int nb)
{
	char					*str;
	int						len;
	unsigned long long int	tmp;

	len = 0;
	tmp = nb;
	if (nb == ULLONG_MAX)
		return (ft_s_llotoa());
	while (tmp > 7)
	{
		tmp = tmp / 8;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 8;
		str[len--] = 48 + tmp;
		nb = nb / 8;
	}
	return (str);
}
