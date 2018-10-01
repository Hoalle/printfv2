/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:12:55 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/28 17:13:35 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_short_write(char *str, short int n, int len)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		i++;
	}
	str[len] = '\0';
	len--;
	while (len >= i)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

char			*ft_short_itoa(short int n, char car)
{
	char		*str;
	int			len;
	short int	temp;

	temp = n;
	len = 0;
	if (n == SHRT_MAX && (car == 'd' || car == 'i'))
		return (str = ft_strdup("32767"));
	if ((unsigned short)n == USHRT_MAX && car == 'D')
		return (str = ft_strdup("65535"));
	if (n == -32768 && (car == 'd' || car == 'i'))
		return (str = ft_strdup("-32768"));
	if (n < 0)
		len++;
	while (temp > 9 || temp < -9)
	{
		temp = temp / 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 2))))
		return (0);
	len++;
	str = ft_short_write(str, n, len);
	return (str);
}
