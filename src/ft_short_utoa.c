/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_utoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 18:00:09 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/01 18:00:18 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		*ft_short_utoa(unsigned short int nb)
{
	char				*str;
	int					len;
	unsigned short int	tmp;

	tmp = nb;
	len = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	if (!(str = (char*)malloc(sizeof(str) * (len + 1))))
		return (0);
	str[len + 1] = '\0';
	while (len >= 0)
	{
		tmp = nb % 10;
		str[len] = 48 + tmp;
		nb = nb / 10;
		len--;
	}
	return (str);
}
