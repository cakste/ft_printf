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

#include <ft_printf.h>

void    precision_handling(t_conv_flags *flags, size_t *raw_len, char *raw)
{
    if (flags->precision == TRUE && flags->precision_count == 0 && ft_atoi(raw) == 0) //&& (flags->conversion == 'x' || flags->conversion == 'X')
		*raw_len = 0;
	if (flags->precision == TRUE && *raw_len == 0 && (flags->conversion == 's' || flags->conversion == 'c' || flags->conversion == 'S' || flags->conversion == 'C'))
		flags->precision_count = 0;
	if (raw[0] == '\0' && (flags->conversion == 'c' || flags->conversion == 'C'))
		*raw_len = 1;
	if (flags->precision_count > flags->width_count)
		flags->width_count = flags->precision_count;
	if (flags->plus == TRUE && raw[0] != '-' && flags->width_count > 0)
		flags->width_count -= 1;
	if (flags->precision && flags->precision_count >= *raw_len && raw[0] == '-')
	{
		*raw_len -= 1;
		flags->width_count -= 1;
	}
	if ((flags->zero == TRUE || flags->precision_count > *raw_len) && flags->precision && flags->width_count > *raw_len)//flags->precision_count)
		flags->zero = FALSE;
	if (flags->space == TRUE && !flags->plus && flags->width_count <= *raw_len && raw[0] != '-' && (flags->conversion == 'd' || flags->conversion == 'D' || flags->conversion == 'i' || flags->conversion == 'I') && ft_atoi(raw) >= 0)
	{
		flags->width_count = *raw_len + 1;
		flags->width = TRUE;
	}
	if (flags->sharp && (flags->conversion == 'o' || flags->conversion == 'O'))// && *raw_len == 0)
	{
		flags->precision = TRUE;
		flags->precision_count = *raw_len + 1;
	}
    if (flags->sharp == TRUE && (flags->conversion == 'x' || flags->conversion == 'X') && ft_atoi(raw) != 0 )//&& flags->zero == FALSE)
		*raw_len += 2;
}

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
		//flags->precision_count += 1;
		str[0] = '-';
		return (1);
	}
    return (0);
}

size_t	cpy_width(t_conv_flags *flags, char *str, size_t raw_len)
{
	size_t	i;
	size_t	taken;

	i = 0;
	taken = (raw_len > flags->precision_count) ? raw_len : flags->precision_count;
	if ((flags->conversion == 's' || flags->conversion == 'S') && flags->precision && raw_len > flags->precision_count)
		taken = flags->precision_count;		
	if (flags->minus == FALSE && flags->width == TRUE && flags->width_count > taken)//flags->precision_count + raw_len) // && flags->precision_count < flags->width_count
	{
		//printf("CPY WIDTH raw_len: %zu flags->widthcount: %zu,  precision_count: %zu\n", raw_len, flags->width_count, flags->precision_count);
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


size_t	cpy_precision(t_conv_flags *flags, char *str, size_t raw_len)
{
	size_t	i;

	i = 0;
	//printf("Precision raw_len: %zu flags->widthcount: %zu,  precision_count: %zu\n", raw_len, flags->width_count, flags->precision_count);
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

size_t	cpy_raw(t_conv_flags *flags, char *str, char *raw, size_t raw_len)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (raw[i] == '\0' && (flags->conversion == 'c' || flags->conversion == 'C'))
	{
		str[i] = raw[j];
		return (i + 1);
	}
	if (flags->precision && flags->precision_count == 0 && ft_atoi(raw) == 0 && flags->conversion != '%')
			return (i);
	if (raw[0] == '-' && (flags->zero == TRUE || flags->precision_count > raw_len) && (flags->conversion == 'd' || flags->conversion == 'D' || flags->conversion == 'i' || flags->conversion == 'I'))
		j++;
	if (flags->precision && (flags->conversion == 'o' || flags->conversion == 'O') && ft_atoi(raw) == 0)
		return (i);
	while (raw[j])
	{
		if (flags->conversion == 's' && flags->precision == TRUE && i >= flags->precision_count)
			break ;
		str[i] = raw[j];
		i++;
		j++;
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
	if (raw == NULL)
	{
		//write(1, "ERROR", 5);
		return ;
	}
	raw_len = ft_strlen(raw);
    precision_handling(flags, &raw_len, raw);
    if (flags->zero == TRUE)
        i += cpy_0x(flags, &str[i + *count_out], raw, &raw_len);
	i += cpy_width(flags, &str[i + *count_out], raw_len);
	if (flags->zero == FALSE)
        i += cpy_0x(flags, &str[i + *count_out], raw, &raw_len);
	i += cpy_precision(flags, &str[i + *count_out], raw_len);
	i += cpy_raw(flags, &str[i + *count_out], raw, raw_len);
	i += cpy_endwidth(flags, &str[i + *count_out], raw_len);
	*count_out += i;
	free(raw);
}