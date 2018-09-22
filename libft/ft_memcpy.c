/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 07:39:44 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 07:39:46 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*start;

	start = dst;
	while (n > 0)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		n--;
		dst++;
		src++;
	}
	return (start);
}
