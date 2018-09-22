/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:30:05 by acakste           #+#    #+#             */
/*   Updated: 2018/09/19 15:30:07 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_conv_flags	*init_flag(void)
{
	t_conv_flags *flags;

	flags = (t_conv_flags*)malloc(sizeof(t_conv_flags));
	if (!flags)
		return (NULL);
	flags->sharp = FALSE;
	flags->minus = FALSE;
	flags->plus = FALSE;
	flags->space = FALSE;
	flags->zero = FALSE;
	flags->width = FALSE;
	flags->width_count = 0;
	flags->precision = FALSE;
	flags->precision_count = 0;	
	flags->modifier = FALSE;
	flags->arg_function = &get_argument;
	flags->conversion = 0;
	return (flags);
}

// reads the entire conversion spec and sets the flags accordingly. 
int	read_conversion_spec(char *str, const char *format, int *count_out, va_list ap)
{
	t_conv_flags	*flags;
	int				i;

	i = 0;
	flags = init_flag();
	//what happens with for example multiple spaces?
	while (format[i] == '0' || format[i] == '#' || format[i] == '-' || format[i] == '+' || format[i] == ' ')
	{
		if (format[i] == '0')// && flags->sharp == FALSE)
			flags->zero = TRUE;
		else if (format[i] == '#')
		{
			flags->sharp = TRUE;
			//flags->zero = FALSE;
		}
		else if (format[i] == '-')
			flags->minus = TRUE;
		else if (format[i] == '+')
			flags->plus = TRUE;
		else if (format[i] == ' ')
			flags->space = TRUE;
		if (flags->minus == TRUE)
			flags->zero = FALSE;
		i++;
	}
	if (ft_atoi(&format[i]) != 0)
	{
		flags->width = TRUE;
		flags->width_count = ft_atoi(&format[i]);
		while (format[i] && format[i] >= '0' && format[i] <= '9')
			i++;
		//write(1, "|",1);
	}
	if (format[i] == '.')
	{
		i++;
		flags->precision = TRUE;
		flags->precision_count = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	if (format[i] == 'h' || format[i] == 'l' || format[i] == 'j' || format[i] == 'z')
	{
		flags->modifier = TRUE;
		if (format[i] == 'h')
			flags->arg_function = &get_argument_h_mod;
		else if (format[i] == 'l')
			flags->arg_function = &get_argument_l_mod;
		else if (format[i] == 'j')
			flags->arg_function = &get_argument_j_mod;
		else if (format[i] == 'z')
			flags->arg_function = &get_argument_z_mod;
		i++;
	}
	if (format[i] == 'h' && flags->arg_function == get_argument_h_mod)
	{
		flags->arg_function = &get_argument_hh_mod;
		i++;
	}
	if (format[i] == 'l' && flags->arg_function == get_argument_l_mod)
	{
		flags->arg_function = &get_argument_ll_mod;
		i++;
	}
	//find correct conversion
	if (format[i] == 's' || format[i]== 'c' || format[i]== 'd' || format[i]== 'i' || format[i]== 'p'
		|| format[i]== 'o' || format[i]== 'u' || format[i]== 'x')
		{
			flags->conversion = format[i];
			i++;
		}
	else if (format[i] == 'S' || format[i]== 'C' || format[i]== 'D' || format[i]== 'I' || format[i]== 'O'
		|| format[i]== 'U' || format[i]== 'X' || format[i]== '%')
		{
			flags->conversion = format[i];
			if (flags->modifier == FALSE || (flags->arg_function == get_argument_h_mod && format[i] == 'U'))
				flags->arg_function = &get_argument_caps;
			i++;
		}
	/*else
	{
		ft_printf("Can't find format conversion '%c'. Check usage.\n", format[i]);
		exit (1);
	}*/
	/*printf("Zero: %d\n", flags->zero);
	printf("sharp: %d\n", flags->sharp);
	printf("minus: %d\n", flags->minus);
	printf("plus: %d\n", flags->plus);
	printf("space: %d\n", flags->space);
	printf("width: %d\n", flags->width);
	printf("width_count: %d\n", flags->width_count);
	printf("precision: %d\n", flags->precision);
	printf("precision_count: %d\n", flags->precision_count);
	printf("modifier: %d\n", flags->modifier);
	printf("modifier_char: %c\n", flags->modifier_char);
	printf("conversion: %c\n", flags->conversion);*/
	strcpy_wflags(str, count_out, flags, ap);
	free(flags);
	return (i + 1);
}

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
