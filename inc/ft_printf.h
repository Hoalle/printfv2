/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 13:25:41 by cperrard          #+#    #+#             */
/*   Updated: 2018/10/02 13:07:54 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <limits.h>

int g_p;
int g_minfd;
char g_zero;
char g_prec;
char g_noprec;
char g_plus;
char g_space;
char g_hash;

int		ft_printf(const char *format, ...);
char	ft_check_flag(char *arg);
int		ft_check_arg(char *f, int i, char **arg, int *j);
void	ft_reset(void);
void	ft_precision(char *arg);

int		ft_print_char(va_list ap, char c);
int		ft_print_nbr(va_list ap, char c, char flag);
int		ft_print_octal(va_list ap, char c, char flag);
int		ft_print_hexa(va_list ap, char c, char flag);
int		ft_print_unsigned(va_list ap, char c, char flag);
int		ft_print_p(va_list ap);
int		ft_print_str(va_list ap, char c);
int		ft_print_percent(char c);

int		ft_precision_nbr(char *nbr, int ret);
int		ft_precision_char(int ret, char c);
int		ft_precision_octal(char *nbr, int ret);
int		ft_precision_hexa(char *nbr, int ret, char *h);
int		ft_precision_unsigned(char *nbr, int ret);
int		ft_precision_p(int ret, char *nbr);
int		ft_precision_str(int ret, char *str);
int		ft_precision_undefined(int tmp, int count, char *f);

int		ft_atoi(char *str);
size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
char	*ft_strdup(const char *src);
void	ft_putstr(char const *s);

char	*ft_otoa(unsigned int n);
char	*ft_long_otoa(unsigned long int n);
char	*ft_long_long_otoa(unsigned long long int n);
char	*ft_char_otoa(unsigned int n);

char	*ft_htoa(unsigned int n, int nb);
char	*ft_long_long_htoa(unsigned long long int n, int nb);
char	*ft_long_htoa(unsigned long int n, int nb);
char	*ft_char_htoa(unsigned int n, int nb);

char	*ft_utoa(unsigned int n);
char	*ft_long_long_utoa(unsigned long long int n);
char	*ft_long_utoa(unsigned long int n);
char	*ft_short_utoa(unsigned short n);
char	*ft_char_utoa(unsigned int n);

char	*ft_itoa(int n);
char	*ft_long_itoa(long int n);
char	*ft_long_long_itoa(long long int n);
char	*ft_short_itoa(short int n, char c);
char	*ft_char_itoa(int n);

int		ft_signed_char(int n);
int		ft_unsigned_char(unsigned int n);

#endif
