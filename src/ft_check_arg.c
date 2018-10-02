/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:47:14 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 16:00:46 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_undefined_copy(char *f, int tmp, int i, int j)
{
	int		ret;
	int		tmp2;
	char	*arg;

	ret = 0;
	tmp2 = tmp;
	arg = (char*)malloc(sizeof(char) * i - tmp2 + 1);
	while (tmp2 <= i)
		arg[j++] = f[tmp2++];
	ft_reset();
	ft_precision(arg);
	if (g_minfd != 0 || g_p != 0)
		ret = ft_precision_undefined(tmp, ret, f);
	if (g_minfd == 0 && g_p == 0)
	{
		tmp2 = 0;
		while (arg[tmp2])
		{
			if (arg[tmp2] != 'h' && arg[tmp2] != 'j' && arg[tmp2] != 'z' &&
					arg[tmp2] != 'l' && arg[tmp2] != ' ' && arg[tmp2] != '#' &&
					arg[tmp2] != '-' && arg[tmp2] != '+' && arg[tmp2] != '.')
			{
				ft_putchar(arg[tmp2++]);
				ret++;
			}
			else
				tmp2++;
		}
	}
	free(arg);
	return (ret);
}

static char	*ft_copy(char *f, int i)
{
	int		len;
	int		tmp;
	char	*str;

	len = 0;
	tmp = i;
	while (f[i] != 'c' && f[i] != 'C' && f[i] != 'd' && f[i] != 'D' &&
	f[i] != 'i' && f[i] != 's' && f[i] != 'S' && f[i] != 'p' && f[i] != 'o' &&
	f[i] != 'O' && f[i] != 'u' && f[i] != 'U' && f[i] != 'x' && f[i] != 'X' &&
	f[i++] != '%')
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len + 1] = '\0';
	i = tmp;
	tmp = 0;
	while (tmp <= len)
		str[tmp++] = f[i++];
	return (str);
}

static int	ft_undefined_percent(char *f, int tmp, int i)
{
	int		ret;
	int		tmp2;
	char	*arg;
	int		j;

	tmp2 = tmp;
	j = 0;
	while (tmp < i)
	{
		if ((f[tmp] < '0' || f[tmp] > '9') && f[tmp] != '%' && f[tmp] != '.' &&
				f[tmp] != '-' && f[tmp] != ' ' && f[tmp] != '+' && f[tmp] != '#'
				&& f[tmp])
			return (ft_undefined_copy(f, tmp2, i - 1, 0));
		tmp++;
	}
	arg = (char*)malloc(sizeof(char) * i - tmp2 + 1);
	tmp = tmp2;
	while (tmp < i)
		arg[j++] = f[tmp++];
	ft_reset();
	ft_precision(arg);
	ret = ft_print_percent('%');
	ret = 1;
	free(arg);
	return (ret);
}

static int	ft_verif(char *arg, int j, int x, int i)
{
	if (j == 1)
	{
		while (arg[i])
		{
			if (arg[i] != 'c' && arg[i] != 'C' && arg[i] != 'u' && arg[i] != 'U'
					&& arg[i] != 'i' && arg[i] != 'd' && arg[i] != 'D' && arg[i]
					!= 'x' && arg[i] != 'X' && arg[i] != 's' && arg[i] != 'S' &&
					arg[i] != 'o' && arg[i] != 'O' && arg[i] != 'p' && arg[i] !=
					'h' && arg[i] != 'j' && arg[i] != 'z' && arg[i] != 'l' &&
					arg[i] != ' ' && arg[i] != '#' && arg[i] != '-' && (arg[i] <
					'0' || arg[i] > '9') && arg[i] != '+' && arg[i] != '.' &&
					arg[i] != '*')
				return (1);
			i++;
		}
	}
	if (j == 2)
	{
		if ((i == '%' && (x == 'c' || x == 'C' || x == 'd' || x == 'D' || x ==
						'i')) || (x == 's' || x == 'S' || x == 'p' || x == 'o'
						|| x == 'O' || x == 'u' || x == 'U' || x == 'x' || x ==
						'X'))
			return (1);
	}
	return (0);
}

int			ft_check_arg(char *f, int i, char **arg, int *j)
{
	int tmp;

	tmp = i;
	while (f[i])
	{
		if (f[i] == 'c' || f[i] == 'C' || f[i] == 'd' || f[i] == 'D' || f[i] ==
				'i' || f[i] == 's' || f[i] == 'S' || f[i] == 'p' || f[i] == 'o'
				|| f[i] == 'O' || f[i] == 'u' || f[i] == 'U' || f[i] == 'x' ||
				f[i] == 'X')
		{
			*arg = ft_copy(f, tmp);
			if (ft_verif(*arg, 1, 0, 0) == 0)
				return (-1);
		}
		if (f[i] == '%')
		{
			*j = i;
			if (ft_verif(*arg, 2, f[i + 1], f[i]) == 1)
				*j = i - 1;
			return (ft_undefined_percent(f, tmp, i));
		}
		i++;
	}
	*j = i - 1;
	return (ft_undefined_copy(f, tmp, i - 1, 0));
}
