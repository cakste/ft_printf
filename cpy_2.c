/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:39:23 by acakste           #+#    #+#             */
/*   Updated: 2018/09/22 18:39:24 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

size_t    cpy_0x(t_conv_flags *flags, char *str, char *raw, size_t *raw_len)
{
    if (ft_atoi(raw) != 0 && (flags->conversion == 'x' || flags->conversion == 'X') && flags->sharp == TRUE)
	{
		str[0] = '0';
		str[1] = flags->conversion;
        return (2);
	}
	else if (flags->plus == TRUE && (flags->conversion == 'd' || flags->conversion == 'D' || flags->conversion == 'i' || flags->conversion == 'I') && ft_atoi(raw) >= 0)
	{
			str[0] = '+';
			return (1);
	}
	else if (raw[0] == '-' && (flags->zero == TRUE || flags->precision_count >= *raw_len) &&(flags->conversion == 'd' || flags->conversion == 'D' || flags->conversion == 'i' || flags->conversion == 'I'))
	{
		str[0] = '-';
		return (1);
	}
    return (0);
}

size_t	cpy_width(t_conv_flags *flags, char *str, size_t raw_len)
{
	size_t	i;
	size_t	taken;

	//printf("CPY WIDTH raw_len: %zu flags->widthcount: %zu,  precision_count: %zu\n", raw_len, flags->width_count, flags->precision_count);
	i = 0;
	taken = (raw_len > flags->precision_count) ? raw_len : flags->precision_count;
	if ((flags->conversion == 's' || flags->conversion == 'S') && flags->precision && raw_len > flags->precision_count)
		taken = flags->precision_count;		
	if (flags->minus == FALSE && flags->width == TRUE && flags->width_count > taken)//flags->precision_count + raw_len) // && flags->precision_count < flags->width_count
	{
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
	if ((flags->conversion == 's' || flags->conversion == 'S') && flags->precision && raw_len > flags->precision_count)
		taken = flags->precision_count;
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
