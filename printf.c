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
#include <ft_printf.h>
#include <stdio.h>

char	*read_format(char *str, const char *format, va_list ap, int *count_out)
{
	int	count_in;

	count_in = 0;
	while (format[count_in] != '\0')
	{
		if (format[count_in] == '%')
		{
			count_in += read_conversion_spec(str, &format[count_in + 1], count_out, ap);
		}
		else
		{
			str[(*count_out)] = format[count_in];
			*count_out += 1;
			count_in++;
		}
	}
	str[*count_out] = '\0';
	return (str);
}

int	ft_sprintf(const char *format, va_list ap)
{
	char	*output;
	int		count_out;

	count_out = 0;
	output = (char*)malloc(sizeof(char) * 4000000);
	if (!output)
		return (0);
	output = read_format(output, format, ap, &count_out);
	write(1, output, count_out);
	free(output);
	return (count_out);
}

int	ft_printf(const char *format, ...)
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
**	* ft_printf("%.2c", NULL); sometims bugs out and prints 4 null chars
**	CONTINUE
**	* bugs,  newline for this ft_printf("%2x", 542);
*/