/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:37:47 by acakste           #+#    #+#             */
/*   Updated: 2018/09/18 17:37:48 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../includes/ft_printf.h"
#include <stdio.h>

/*
int		cpy_width(int i, t_conv_flags *flags, size_t raw_len, char *str)
{
	if (flags->minus == FALSE && flags->width == TRUE && flags->width_count > raw_len) // && flags->precision_count < flags->width_count
	{
		while (i + raw_len < flags->width_count - flags->plus)
		{
			str[i] = (flags->zero == TRUE) ? '0' : ' ';
			i++;
		}
	}
	return (i);
}
*/

/*

void	strcpy_wflags(char *str, int *count_out, t_conv_flags *flags, va_list ap)
{
	char	*raw;
	size_t	raw_len;
	size_t	i;
	size_t 	j;

	i = 0;
	j = 0;
	raw = flags->arg_function(ap, flags);
	if (!raw)
	{
		write(1, "ERROR", 5);
		exit (1);
	}
	//still want? !flags->width && 
	if (flags->precision == TRUE && flags->precision_count == 0 && (flags->conversion == 'x' || flags->conversion == 'X') && ft_atoi(raw) == 0)
		raw_len = 0;
	else
		raw_len = ft_strlen(raw);
	//in raw, we should now have the raw data. Check flags and copy accordingly. If no flags, raw is simply copied to str.
	//if (!flags->minus), width first.
	//if (flags->precision_count == 0)
	//	flags->precision_count += ft_strlen(raw);
	if (flags->conversion == 's' && flags->precision && raw_len == 0)
		flags->precision_count = 0;
	if (flags->conversion == 's' && flags->precision && flags->precision_count < raw_len)
		raw_len -= flags->precision_count;
	else if (flags->precision_count > raw_len)
		raw_len = flags->precision_count;
		//for   ft_printf("%#08x", 42); should print   2. (    8) -->0x00002a<--
	
	
	if (raw[j] != '0' && (flags->conversion == 'x' || flags->conversion == 'X') && flags->sharp == TRUE)
		raw_len += 2;
	if (flags->zero == TRUE && raw[j] != '0' && (flags->conversion == 'x' || flags->conversion == 'X') && flags->sharp == TRUE)
	{
		str[i++ + *count_out] = '0';
		str[i++ + *count_out] = flags->conversion;
		raw_len -= 2;
	}
	if (flags->minus == FALSE && flags->width == TRUE && flags->width_count > raw_len) // && flags->precision_count < flags->width_count
	{
		while (i + raw_len < flags->width_count - flags->plus)
		{
			str[i + *count_out] = (flags->zero == TRUE) ? '0' : ' ';
			i++;
		}
	}
	//printf("%d\n", i + *count_out);
	//check if any precision. Numbers always print atleast there full length. Add zeros afterwards. Only print precision amount of chars.
	if (flags->plus == TRUE && (flags->conversion == 'd' || flags->conversion == 'D' || flags->conversion == 'i' || flags->conversion == 'I') && ft_atoi(raw) >= 0)
	{
		str[i++ + *count_out] = '+';		
	}
	//plus and 0x for hex
	if (flags->zero == FALSE && raw[j] != '0' && (flags->conversion == 'x' || flags->conversion == 'X') && flags->sharp == TRUE)
	{
		str[i++ + *count_out] = '0';
		str[i++ + *count_out] = flags->conversion;
	}
	if (flags->precision == TRUE)
	{
		while (j + raw_len < flags->precision_count)
		{
			str[i + *count_out] = '0';
			i++;
			j++;
		}
	}

	//might wanna control a negative number input somewhere


	//cpy number
	while (raw[j] && j < raw_len)
	{
		//write(1, "|", 1);
		if (flags->conversion == 's' && flags->precision == TRUE && j >= flags->precision_count)
			break ;
		str[i + *count_out] = raw[j];
		i++;
		j++;
	}
	//cpy any width (spaces) with flag->minus
	if (flags->minus == TRUE)
	{
		while (i < flags->width_count)
		{
			str[i + *count_out] = ' ';
			i++;
		}
	}
	*count_out += i;
	free(raw);
}*/

int	ft_sprintf(const char *format, va_list ap)
{
	int printed;
	char *output;

	printed = 0;
	output = (char*)malloc(sizeof(char) * __INT_MAX__ + 1);
	if (!output)
		return (0);
	output = read_format(output, format, ap);
	printed = ft_strlen(output);
	write(1, output, printed);
	free(output);
	return (printed);
}

int	ft_printf(char *format, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, format);
	printed = ft_sprintf(format, ap);
	va_end(ap);
	return (printed);
}

/*
**	TODO:
**	* fix all the get arg functions with correct data types. Might need need itoa functions as well.
**	* set macros for all the bases
**	* cut down code and split into different files
**	* deal with capital conversions
**  * are size_t and ptrdiff_t the same size? Eg: should we use the for 't' and 'z' modifiers
**	* return value?
**	* wide chars
	//ft_printf("% w\n");
	//ft_printf("%l x\n", 2);
**  * # flag
**	* # flag, octal force one zero
**	* maybe return void* from all the get arg functions
**	* utf-8 wikipedia, grab int size for widechars. Then count how many bytes to print. wint_t
**	* for input ft_printf("%2x", 542); it owerflows correctly when this is put in read_specs printf("%zu\n", flags->width_count - ft_strlen(raw));

**	CONTINUE
**	* bugs,  newline for this ft_printf("%2x", 542);
*/