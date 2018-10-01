/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:51:44 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 16:00:38 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char			*ft_otoa(unsigned int nb)
{
	char			*str;
	int				len;
	unsigned int	tmp;

	tmp = nb;
	len = 0;
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
		str[len] = 48 + tmp;
		nb = nb / 8;
		len--;
	}
	return (str);
}
