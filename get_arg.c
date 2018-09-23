/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:33:59 by acakste           #+#    #+#             */
/*   Updated: 2018/09/19 15:34:00 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*might need different itoa functions etc for all the modifiers?*/
//changed to uintmax
char *get_argument(va_list ap, t_conv_flags *flags)
{
	if (flags->conversion == 's')
		return (ft_strdup(va_arg(ap, char*)));
	else if (flags->conversion == 'c')
		return (ft_str_of_char(va_arg(ap, int)));
	else if (flags->conversion == 'd' || flags->conversion == 'i')
		return (ft_itoa_base((int)va_arg(ap, int), BASE_10));
	else if (flags->conversion == 'p')
		return (ft_memaddr((unsigned long long)va_arg(ap, void*), BASE_16_a));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned((unsigned int)va_arg(ap, unsigned int), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned((unsigned int)va_arg(ap, unsigned int), BASE_10));
	else if (flags->conversion == 'x')
		return (ft_itoa_base_unsigned((unsigned int)va_arg(ap, unsigned int), BASE_16_a));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}
/*
char *get_argument_sharp(va_list ap, t_conv_flags *flags)
{
	if (flags->conversion == 's')
		return (ft_strdup((char*)va_arg(ap, char*)));
	else if (flags->conversion == 'c')
		return (ft_str_of_char((int)va_arg(ap, int)));
	else if (flags->conversion == 'd' || flags->conversion == 'i')
		return (ft_itoa_base((int)va_arg(ap, int), BASE_10));
	else if (flags->conversion == 'p')
		return (ft_memaddr((unsigned long long)va_arg(ap, void*), BASE_16_a));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned int), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned int), BASE_10));
	else if (flags->conversion == 'x')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned int), BASE_16_A));
	else if (flags->conversion == 'X')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned int), BASE_16_A));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}*/

//wide chars for 'S' and 'C'
char	*get_argument_caps(va_list ap, t_conv_flags *flags)
{
	if (flags->conversion == 'S')
		return ((char*)ft_strdup_wide((wchar_t*)va_arg(ap, int*)));
	else if (flags->conversion == 'C')
		return (ft_str_of_char(va_arg(ap, int)));
	else if (flags->conversion == 'D' || flags->conversion == 'I')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long), BASE_10));
	else if (flags->conversion == 'O')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long), BASE_8));
	else if (flags->conversion == 'U')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long), BASE_10));
	else if (flags->conversion == 'X')
		return (ft_itoa_base_unsigned((unsigned int)va_arg(ap, unsigned int), BASE_16_A));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

//obs skickar int istallet for unsigned char
char *get_argument_hh_mod(va_list ap, t_conv_flags *flags)
{
    if (flags->conversion == 'd' || flags->conversion== 'i')
		return (ft_itoa_base((signed char)va_arg(ap, int), BASE_10));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned((unsigned char)va_arg(ap, int), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned((unsigned char)va_arg(ap, int), BASE_10));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		return (ft_itoa_base_unsigned((unsigned char)va_arg(ap, int), BASE_16_a));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

char *get_argument_h_mod(va_list ap, t_conv_flags *flags)
{
    if (flags->conversion == 'd' || flags->conversion== 'i')
		return (ft_itoa_base((short)va_arg(ap, int), BASE_10));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned((unsigned short)va_arg(ap, int), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned((unsigned short)va_arg(ap, int), BASE_10));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		return (ft_itoa_base_unsigned((unsigned short)va_arg(ap, int), BASE_16_a));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

//watch wide char
char *get_argument_l_mod(va_list ap, t_conv_flags *flags)
{
	if (flags->conversion == 's')
		return ((char*)ft_strdup_wide(va_arg(ap, wchar_t*)));
	else if (flags->conversion == 'c')
		return (ft_str_of_char(va_arg(ap, wint_t)));
	else if (flags->conversion == 'd' || flags->conversion== 'i')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long), BASE_10));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned((unsigned long)va_arg(ap, unsigned long), BASE_10));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		return (ft_itoa_base_unsigned(va_arg(ap, unsigned long), BASE_16_a));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

char *get_argument_ll_mod(va_list ap, t_conv_flags *flags)
{
    if (flags->conversion == 'd' || flags->conversion== 'i')
		return (ft_itoa_base(va_arg(ap, long long), BASE_10));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned((unsigned long long)va_arg(ap, unsigned long long), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned((unsigned long long)va_arg(ap, unsigned long long), BASE_10));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		return (ft_itoa_base_unsigned((unsigned long long)va_arg(ap, unsigned long long), BASE_16_a));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

char *get_argument_j_mod(va_list ap, t_conv_flags *flags)
{
    if (flags->conversion == 'd' || flags->conversion== 'i')
		return (ft_itoa_base(va_arg(ap, intmax_t), BASE_10));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned(va_arg(ap, uintmax_t), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned(va_arg(ap, uintmax_t), BASE_10));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
	{
		return (ft_itoa_base_unsigned((uintmax_t)va_arg(ap, uintmax_t), BASE_16_a));
	}
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

char *get_argument_t_mod(va_list ap, t_conv_flags *flags)
{
	if (flags->conversion == 'd' || flags->conversion== 'i')
		return (ft_itoa_base(va_arg(ap, ptrdiff_t), BASE_10));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned(va_arg(ap, size_t), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned(va_arg(ap, size_t), BASE_10));
	else if (flags->conversion == 'x')
		return (ft_itoa_base_unsigned(va_arg(ap, size_t), BASE_16_a));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

char *get_argument_z_mod(va_list ap, t_conv_flags *flags)
{
	if (flags->conversion == 'd' || flags->conversion== 'i')
		return (ft_itoa_base(va_arg(ap, ptrdiff_t), BASE_10));
	else if (flags->conversion == 'o')
		return (ft_itoa_base_unsigned(va_arg(ap, size_t), BASE_8));
	else if (flags->conversion == 'u')
		return (ft_itoa_base_unsigned(va_arg(ap, size_t), BASE_10));
	else if (flags->conversion == 'x' || flags->conversion == 'X')
		return (ft_itoa_base_unsigned(va_arg(ap, size_t), BASE_16_a));
	else if (flags->conversion == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}


