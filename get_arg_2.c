/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 18:34:46 by acakste           #+#    #+#             */
/*   Updated: 2018/09/22 18:34:47 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
		return (ft_itoa_base_unsigned((uintmax_t)va_arg(ap, uintmax_t), BASE_16_a));
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
