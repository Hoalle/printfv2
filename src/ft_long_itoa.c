/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:07:37 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/28 17:09:30 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char		*ft_long_write(char *str, long int n, int len)
{
	long int	i;

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

char			*ft_long_itoa(long int n)
{
	char		*str;
	int			len;
	long int	temp;

	temp = n;
	len = 0;
	if (n == (-9223372036854775807 - 1))
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
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
	str = ft_long_write(str, n, len);
	return (str);
}
