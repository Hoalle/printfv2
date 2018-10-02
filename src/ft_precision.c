/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:06:57 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 16:10:00 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	int		ft_check_gzero(char *arg, int j)
{
	while ((arg[j] < '0' || arg[j] > '9') && arg[j])
		j++;
	if (arg[j] == '0')
		g_zero = '0';
	if (g_zero == '0' && arg[j + 1] != '\0')
		j++;
	if (arg[j] < '0' || arg[j] > '9')
	{
		while ((arg[j] < '0' || arg[j] > '9') && arg[j])
			j++;
	}
	return (j);
}

static	void	ft_precision_part1(char *arg, int i, int j)
{
	char	*nb;
	int		tmp;

	i = ft_check_gzero(arg, j);
	tmp = i;
	while (arg[tmp] >= '0' && arg[tmp] <= '9' && arg[tmp])
		tmp++;
	nb = (char*)malloc(sizeof(char) * tmp - i + 1);
	while (arg[i] >= '0' && arg[i] <= '9' && arg[i])
		nb[j++] = arg[i++];
	nb[j] = '\0';
	g_p = ft_atoi(nb);
	j = 0;
	free(nb);
	i++;
	tmp = i;
	while (arg[tmp] >= '0' && arg[tmp] <= '9' && arg[tmp])
		tmp++;
	nb = (char*)malloc(sizeof(char) * tmp - i + 1);
	while (arg[i] >= '0' && arg[i] <= '9' && arg[i])
		nb[j++] = arg[i++];
	nb[j] = '\0';
	g_minfd = ft_atoi(nb);
	free(nb);
}

static	void	ft_precision_part2(char *arg, int i, int j)
{
	char	*nb;
	int		tmp;

	i = ft_check_gzero(arg, j);
	tmp = i;
	while (arg[tmp] >= '0' && arg[tmp] <= '9' && arg[tmp])
		tmp++;
	nb = (char*)malloc(sizeof(char) * tmp - i + 1);
	while (arg[i] >= '0' && arg[i] <= '9' && arg[i])
		nb[j++] = arg[i++];
	nb[j] = '\0';
	g_minfd = ft_atoi(nb);
	free(nb);
}

void			ft_precision(char *arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_reset();
	while (arg[i])
	{
		if (arg[i] == '.')
			g_prec = '.';
		if (arg[i] == '#')
			g_hash = '#';
		if (arg[i] == '-')
			g_noprec = '-';
		if (arg[i] == '+')
			g_plus = '+';
		if (arg[i] == ' ')
			g_space = ' ';
		i++;
	}
	i = 0;
	if (g_prec == '.')
		ft_precision_part1(arg, i, j);
	else
		ft_precision_part2(arg, i, j);
//	if (g_prec == '.' && g_zero == '0')
//		g_zero = '\0';
}
