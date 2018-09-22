/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:42:26 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 10:42:27 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	new = (void*)malloc(size);
	if (new == NULL)
		return (NULL);
	ft_memset(new, 0, size);
	return (new);
}
