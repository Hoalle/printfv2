/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 11:56:50 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 12:09:59 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_print(int ret, char *str)
{
	ft_putstr(str);
	ret = ft_strlen(str);
	return (ret);
}

int			ft_print_str(va_list ap, char c)
{
	int		ret;
	char	*str;
	wchar_t	*wstr;

	ret = 0;
	if (c == 's')
	{
		str = va_arg(ap, char*);
		if (str == NULL)
			str = "(null)";
	}
	if (c == 'S')
	{
		if ((wstr = va_arg(ap, wchar_t*)) == NULL)
		{
			ft_putstr("(null)");
			return (6);
		}
	}
	if (g_p > 0 || g_minfd > 0)
		ret = ft_precision_str(ret, str);
	else
		ret = ft_print(ret, str);
	return (ret);
}
