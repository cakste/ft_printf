/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:42:11 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 11:42:12 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	new = (char*)malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (*s1 != '\0')
			new[i] = *s1++;
		else
			new[i] = *s2++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
