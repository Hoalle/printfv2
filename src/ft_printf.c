/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:05:30 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 14:18:24 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int		ft_letter(va_list ap, char c, char flag)
{
	if (c == 'c' || c == 'C')
		return (ft_print_char(ap, c));
	else if (c == 'd' || c == 'D' || c == 'i')
		return (ft_print_nbr(ap, c, flag));
	else if (c == 's' || c == 'S')
		return (ft_print_str(ap, c));
	else if (c == 'o' || c == 'O')
		return (ft_print_octal(ap, c, flag));
	else if (c == 'x' || c == 'X')
		return (ft_print_hexa(ap, c, flag));
	else if (c == 'u' || c == 'U')
		return (ft_print_unsigned(ap, c, flag));
	else if (c == 'p')
		return (ft_print_p(ap));
	return (0);
}

static int		ft_printf_suite(va_list ap, char *format, int ret, int *i)
{
	char	flag;
	char	*arg;
	int		tmp;
	int		j;

	arg = NULL;
	j = 0;
	tmp = ft_check_arg((char*)format, (*i) + 1, &arg, &j);
	if (tmp == -1)
	{
		if (ft_strlen(arg) == 1)
			ret += ft_letter(ap, format[(*i) + 1], '0');
		else
		{
			ft_precision(arg);
			flag = ft_check_flag(arg);
			ret += ft_letter(ap, format[(*i) + ft_strlen(arg)], flag);
		}
		(*i) += ft_strlen(arg);
		free(arg);
		return (ret);
	}
	(*i) = j;
	free(arg);
	return (ret + tmp);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	int		ret;
	int		i;

	va_start(ap, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		ft_reset();
		if (format[i] == '%')
			ret = ft_printf_suite(ap, (char*)format, ret, &i);
		else if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ret++;
		}
		i++;
	}
	return (ret);
}
