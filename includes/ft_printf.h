/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 16:31:05 by acakste           #+#    #+#             */
/*   Updated: 2018/09/18 16:32:08 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF
# include <stdarg.h>
# include <wchar.h>
# include <inttypes.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define TRUE 1
# define FALSE 0
# define BASE_10 "0123456789"
# define BASE_16_a "0123456789abcdef"
# define BASE_16_A "0123456789ABCDEF"
# define BASE_8 "01234567"
# define INT(x) (x == 'd' || x == 'i')
# define LONG(x) (x == 'D' || x == 'I')

typedef unsigned char	t_bool;
typedef struct			s_conv_flags
{
	t_bool	sharp;
	t_bool	minus;
	t_bool	plus;
	t_bool	space;
	t_bool	zero;
	t_bool	width;
	size_t	width_count;
	t_bool	precision;
	size_t	precision_count;
	t_bool	modifier;
	char	*(*arg_function)();
	char	conversion;
}						t_conv_flags;

int		ft_num_len(intmax_t num, int base_len);
int		ft_num_len_unsigned(uintmax_t num, int base_len);
char	*ft_itoa_base(intmax_t num, char *base);
char	*ft_itoa_base_unsigned(uintmax_t num, char *base);
char	*ft_str_of_char(int c);
char	*ft_memaddr(uintmax_t addr, char *base);
char	*get_argument(va_list ap, t_conv_flags *flags);
char	*get_argument_hh_mod(va_list ap, t_conv_flags *flags);
char	*get_argument_h_mod(va_list ap, t_conv_flags *flags);
char	*get_argument_l_mod(va_list ap, t_conv_flags *flags);
char	*get_argument_ll_mod(va_list ap, t_conv_flags *flags);
char	*get_argument_j_mod(va_list ap, t_conv_flags *flags);
char	*get_argument_t_mod(va_list ap, t_conv_flags *flags);
char	*get_argument_z_mod(va_list ap, t_conv_flags *flags);
char	*get_argument_caps(va_list ap, t_conv_flags *flags);
char *get_argument_sharp(va_list ap, t_conv_flags *flags);
size_t  ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
wchar_t	*ft_strdup_wide(wchar_t *s1);
size_t  ft_strlen_wide(wchar_t *s);
int		ft_printf(const char *format, ...);
int		ft_sprintf(const char *format, va_list ap);
char	*read_format(char *str, const char *format, va_list ap, int *count_out);
int		read_conversion_spec(char *str, const char *format, int *count_out, va_list ap);
void	strcpy_wflags(char *str, int *count_out, t_conv_flags *flags, va_list ap);
int		ft_atoi(const char *str);

#endif
