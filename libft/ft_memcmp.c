/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:22:12 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 08:22:14 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;

	s1_cpy = (unsigned char*)s1;
	s2_cpy = (unsigned char*)s2;
	while (n > 0 && *s1_cpy == *s2_cpy)
	{
		s1_cpy++;
		s2_cpy++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1_cpy - *s2_cpy);
}
