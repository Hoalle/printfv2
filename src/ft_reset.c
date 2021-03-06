/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 17:02:47 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/26 17:06:26 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_reset(void)
{
	g_minfd = 0;
	g_p = 0;
	g_noprec = '\0';
	g_prec = '\0';
	g_zero = '\0';
	g_plus = '\0';
	g_space = '\0';
	g_hash = '\0';
}
