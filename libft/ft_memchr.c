/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 08:12:43 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 08:12:46 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;

	s_cpy = (unsigned char*)s;
	while (n > 0)
	{
		if (*s_cpy == (unsigned char)c)
			return (s_cpy);
		s_cpy++;
		n--;
	}
	return (NULL);
}
