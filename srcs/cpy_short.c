/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:11:21 by acakste           #+#    #+#             */
/*   Updated: 2018/09/20 17:11:22 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    precision_handling(t_conv_flags *flags, size_t *raw_len, char *raw)
{
    if (flags->precision == TRUE && flags->precision_count == 0 && (flags->conversion == 'x' || flags->conversion == 'X') && ft_atoi(raw) == 0)
		*raw_len = 0;
	if (flags->conversion == 's' && flags->precision == TRUE && *raw_len == 0)
		flags->precision_count = 0;
	if (flags->precision_count > flags->width_count)
		flags->width_count = flags->precision_count;
	if (flags->plus == TRUE && flags->width_count > 0)
		flags->width_count -= 1;
	//else if (flags->conversion == 's' && flags->precision && flags->precision_count < *raw_len)
	//	*raw_len -= flags->precision_count;
	//else if (flags->precision_count > *raw_len)
	//	*raw_len = flags->precision_count;
    else if (flags->sharp == TRUE && (flags->conversion == 'x' || flags->conversion == 'X') && ft_atoi(raw) != 0 )//&& flags->zero == FALSE)
		*raw_len += 2;
}

size_t    cpy_0x(t_conv_flags *flags, char *str, char *raw)
{
    if (ft_atoi(raw) != 0 && (flags->conversion == 'x' || flags->conversion == 'X') && flags->sharp == TRUE)
	{
		str[0] = '0';
		str[1] = flags->conversion;
        return (2);
	}
    return (0);
}

size_t	cpy_width(t_conv_flags *flags, char *str, size_t raw_len)
{
	size_t	i;
	size_t	taken;

	i = 0;
	taken = (raw_len > flags->precision_count) ? raw_len : flags->precision_count;
	//write(1, "|", 1);
	if (flags->minus == FALSE && flags->width == TRUE && flags->width_count > taken)//flags->precision_count + raw_len) // && flags->precision_count < flags->width_count
	{
		//printf("raw_len: %zu flags->widthcount: %zu,  precision_count: %zu\n", raw_len, flags->width_count, flags->precision_count);
		while (i + taken < (flags->width_count))
		{
			str[i] = (flags->zero == TRUE) ? '0' : ' ';
			i++;
		}
	}
	return (i);
}

size_t cpy_endwidth(t_conv_flags *flags, char *str, size_t raw_len)
{
	size_t i;
	size_t	taken;

	i = 0;
	taken = (raw_len > flags->precision_count) ? raw_len : flags->precision_count;
	if (flags->minus == TRUE)
	{
		//printf("raw_len: %zu flags->widthcount: %zu,  precision_count: %zu\n", raw_len, flags->width_count, flags->precision_count);
		while (i + taken < flags->width_count)
		{
			str[i] = ' ';
			i++;
		}
	}
	return (i);
}


size_t	cpy_precision(t_conv_flags *flags, char *str, size_t raw_len)
{
	size_t	i;

	i = 0;
	if (flags->precision == TRUE && flags->precision_count > raw_len)
	{
		while (i < flags->precision_count - raw_len)
		{
			str[i] = '0';
			i++;
		}
	}
	return (i);
}

size_t	cpy_raw(t_conv_flags *flags, char *str, char *raw)//, size_t raw_len)
{
	size_t i;

	i = 0;
	if ((flags->conversion == 'x' || flags->conversion == 'X') && flags->precision && flags->precision_count == 0 && ft_atoi(raw) == 0)
		return (i); 
	while (raw[i])
	{
		if (flags->conversion == 's' && flags->precision == TRUE && i >= flags->precision_count)
			break ;
		str[i] = raw[i];
		i++;
	}
	return (i);
}

void	strcpy_wflags(char *str, int *count_out, t_conv_flags *flags, va_list ap)
{
	char	*raw;
	size_t	raw_len;
	size_t	i;
	size_t 	j;

	i = 0;
	j = 0;
	raw = flags->arg_function(ap, flags);
	raw_len = ft_strlen(raw);
    precision_handling(flags, &raw_len, raw);
    if (flags->zero == TRUE)
        i += cpy_0x(flags, &str[i + *count_out], raw);
	i += cpy_width(flags, &str[i + *count_out], raw_len);
	if (flags->plus == TRUE && (flags->conversion == 'd' || flags->conversion == 'D' || flags->conversion == 'i' || flags->conversion == 'I') && ft_atoi(raw) >= 0)
		str[i++ + *count_out] = '+';
	if (flags->zero == FALSE)
        i += cpy_0x(flags, &str[i + *count_out], raw);
	i += cpy_precision(flags, &str[i + *count_out], raw_len);
	i += cpy_raw(flags, &str[i + *count_out], raw);
	i += cpy_endwidth(flags, &str[i + *count_out], raw_len);
	*count_out += i;
	free(raw);
}