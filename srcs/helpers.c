/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 07:57:40 by acakste           #+#    #+#             */
/*   Updated: 2018/09/19 07:57:44 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"

char	*ft_str_of_char(int c)
{
	char *new;
	if (c == '\0')
	{
		new = (char*)malloc(sizeof(char) * 1);
		new[1] = '\0';
		return (new);
	}
	new = (char*)malloc(sizeof(char) * 2);
	if (!new)
		return (NULL);
	new[0] = (char)c;
	new[1] = '\0';
	return (new);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_num_len(intmax_t num, int base_len)
{
	int	bytes;

	if (num == 0)
		return (1);
	bytes = (num < 0) ? 1 : 0;
	while (num != 0)
	{
		num /= base_len;
		bytes++;
	}
	return (bytes);
}

int		ft_num_len_unsigned(uintmax_t num, int base_len)
{
	int	bytes;

	if (num == 0)
		return (1);
	bytes = 0;
	while (num != 0)
	{
		num /= base_len;
		bytes++;
	}
	return (bytes);
}


char	*ft_itoa_base(intmax_t num, char *base)
{
	char	*buff;
	int		len;
	int		base_len;
	int		stop;

	base_len = ft_strlen(base);
	len = ft_num_len(num, base_len);
	buff = (char*)malloc(sizeof(char) * len + 1);
	buff[len] = '\0';
	len--;
	if (num < 0)
		buff[0] = '-';
	stop = (num < 0) ? 1 : 0;
	while (len >= stop)
	{
		buff[len] = (num < 0) ? base[(num % base_len) * -1]: base[num % base_len];
		num /= base_len;
		len--;
	}
	return (buff);
}

char	*ft_itoa_base_unsigned(uintmax_t num, char *base)
{
	char	*buff;
	int		len;
	int		base_len;

	base_len = ft_strlen(base);
	len = ft_num_len_unsigned(num, base_len);
	buff = (char*)malloc(sizeof(char) * len + 1);
	buff[len] = '\0';
	len--;
	while (len >= 0)
	{
		buff[len] = base[num % base_len];
		num /= base_len;
		len--;
	}
	return (buff);
}

char	*ft_memaddr(uintmax_t addr, char *base)
{
	char	s[3];
	char	*hex;
	char	*address;

	s[0] = '0';
	s[1] = 'x';
	s[2] = '\0';
	hex = ft_itoa_base_unsigned(addr, base);
	address = ft_strjoin(s, hex);
	free(hex);
	return (address);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	sum;
	int		sign;

	i = 0;
	sum = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((((sum * 10) + (str[i] - 48)) - (str[i] - 48)) / 10 != sum)
			return ((sign == -1) ? 0 : -1);
		sum = (sum * 10) + (str[i] - 48);
		i++;
	}
	return (sum * sign);
}

/*
int		ft_putnbr_base(unsigned long long num, char	*base)
{
	int	chrs;

	chrs = 0;
	if (num >= ft_strlen(base))
		chrs += ft_putnbr_base(num / (ft_strlen(base)), base);
	return (chrs + ft_putchar(base[num % ft_strlen(base)]));
}
*/