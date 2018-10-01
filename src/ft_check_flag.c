/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:47:12 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/26 17:00:52 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char		ft_check_flag(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'h' && arg[i] == 'h')
			return ('H');
		else if (arg[i] == 'h' && arg[i + 1] != 'h')
			return ('h');
		else if (arg[i] == 'l' && arg[i + 1] == 'l')
			return ('L');
		else if (arg[i] == 'l' && arg[i + 1] != 'l')
			return ('l');
		else if (arg[i] == 'j')
			return ('j');
		else if (arg[i] == 'z')
			return ('z');
		i++;
	}
	return ('0');
}
