/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:34:35 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 07:34:44 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;

	b2 = (unsigned char*)b;
	while (len > 0)
	{
		*b2 = (unsigned char)c;
		b2++;
		len--;
	}
	return (b);
}
