/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acakste <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:33:08 by acakste           #+#    #+#             */
/*   Updated: 2018/09/10 11:33:10 by acakste          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	new = (char*)malloc(sizeof(char) * len + 1);
	if (new)
	{
		i = 0;
		while (i < len)
		{
			new[i] = s[i + start];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
